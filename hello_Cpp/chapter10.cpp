# include <iostream>
# include "hello_Cpp.h"
# include <vector>
# include <list>
# include <array>
# include <numeric>
# include <iterator>
# include <functional>
using namespace std;
using namespace std::placeholders;

bool mod5(const int a, const int b)
{
	return a % 5 < b % 5;
}

auto func() -> int
{
	return 1;
}

void fc1()
{
	size_t x1 = 39;
	auto f = [x1] { return x1; };    // 值捕获（即拷贝）
	x1 = 0;
	cout << f() << endl;
}

void fc2()
{
	size_t x1 = 39;
	auto f = [&x1] { return x1; };    // 引用捕获，须保证lambda执行时该变量存在
	x1 = 0;
	cout << f() << endl;
}

int chapter10()
{
	vector<int> v1 = { 1,2,3,4,5,6,7,8,9 };
	vector<string> v2 = { "Lebron","James","is","the","GOAT","!!!" };

	// accumulate，对于数值vector：求和
	int sum1 = accumulate(v1.cbegin(), v1.cend(), 0);
	// 对于字符串：连接
	// 显示创建string("")如果改为空串""将出错，原因在于""是const char*类型，此类型没有运算符+
	string sum2 = accumulate(v2.cbegin(), v2.cend(), string(""));
	cout << sum1 << endl;
	cout << sum2 << endl;

	// fill与fill_n
	fill(v1.begin(), v1.end(), 0);    // 将所有元素重置为0
	fill_n(v1.begin(), v1.size(), 0);    // 与上一句等价
	vector<int> v3;    // 空向量
	// 利用back_inserter往向量中依次插入10个3
	fill_n(back_inserter(v3), 10, 3);
	// 等价于
	// auto it = back_inserter(v3);
	// for (int i = 0; i < 10; ++i)
	//     *it = 3;
	for (auto& i : v3)
		cout << i << endl;

	// replace 将所有3替换为33
	replace(v3.begin(), v3.end(), 3, 33);
	for (auto& i : v3)
		cout << i << endl;

	vector<int> v4;
	// replace_copy 将替换后的向量拷贝至另一个向量，原向量保持不变
	replace_copy(v3.cbegin(), v3.cend(), back_inserter(v4), 33, 5);
	for (auto& i : v4)
		cout << i << endl;

	// sort与unique
	vector<int> v5 = { 9,3,3,1,5,6,7,8,2,2,3,5,4,4,7,6 };
	sort(v5.begin(), v5.end());    // 排序
	for (auto& i : v5)
		cout << i << endl;    // 1223334455667789
	auto last_unique = unique(v5.begin(), v5.end());    // 将不重复的元素放在前面，重复的排在后面
	for (auto& i : v5)
		cout << i << endl;    // 1234567895667789 注意与sort的结果对比，元素发生了变化
	cout << endl;
	// unique的返回值为指向第一个开始重复的元素的迭代器
	for (auto i = last_unique; i != v5.cend(); ++i)
		cout << *i << endl;    // 5667789，可用erase删除重复的元素

	cout << endl;
	// 谓词，按照自定义函数排序
	sort(v5.begin(), v5.end(), mod5);
	for (auto& i : v5)
		cout << i << endl;    // 5516662777388499
	cout << endl;
	// stable_sort 排序的同时，对于相等的元素维持原相对顺序不变
	vector<int> v6 = { 9,3,3,1,5,6,7,8,2,2,3,5,4,4,7,6 };
	stable_sort(v6.begin(), v6.end(), mod5);
	for (auto& i : v6)
		cout << i << endl;    // 5516672273383944

	// 尾置返回
	// auto func(参数列表) -> 返回类型
	// {
	//     函数体
	//  }
	cout << func() << endl;

	cout << endl;
	// lambda [捕获列表（实参）](形参列表){函数体}
	vector<int> v7 = { 9,3,3,1,5,6,7,8,2,2,3,5,4,4,7,6 };
	stable_sort(v7.begin(), v7.end(),
		        [](const int a, const int b)
		            { return a % 5 < b % 5; });
	for (auto& i : v7)
		cout << i << endl;    // 5516672273383944

	// find_if 返回指向第一个满足条件的元素的迭代器
	int base = 8;
	auto p = find_if(v7.begin(), v7.end(),
		             [base](const int a)
		                 { return a > base; });
	cout << *p << endl;

	// for_each 对迭代器指向的每个元素调用一个可调用对象
	for_each(p, v7.end(),
		    [](const int a)
		    { cout << a << " "; });
	cout << endl;


	// lambda 对象的创建时机：值捕获和引用捕获
	fc1();    // 39
	fc2();    // 0

	cout << endl;
	// lambda 函数体中一旦包含了除return以外的语句，编译器假定其返回void
	// 因此若要返回特定类型的值，需使用尾置返回指定
	vector<int> v8 = { -1,0,3,-9,8,5 };
	transform(v8.begin(), v8.end(), v8.begin(),
		     [](int a) -> int
		     { if (a < 0) return -a; else return a; });
	for (auto& i : v8)
		cout << i << endl;
	cout << endl;

	// 按照字符长度排序
	vector<string> v9 = { "a", "aa", "aaa", "aaaa" };
	sort(v9.begin(), v9.end(), isShorter);
	for (auto& i : v9)
		cout << i << " ";
	cout << endl;

	v9 = { "a", "aa", "aaa", "aaaa" };
	auto excg_isShorter = bind(isShorter, _2, _1);    // 利用bind重排参数顺序
	sort(v9.begin(), v9.end(), excg_isShorter);    // 相当于逆序排列，即按长度从大到小
	for (auto& i : v9)
		cout << i << " ";
	cout << endl;

	// 若要利用bind捕获ostream对象，需要对其进行ref调用
	// ostream &print(ostream &os, const string &s, char c) { return os << s << c; }
	// for_each(v9.begin(), v9.end(),
	//          bind(print, ref(os), _1, ' '));

	cout << endl;
	// inserter 普通、前（总是在第一个元素前插入）、后（总是在最后一个元素后插入）
	list<int> lst1 = { 1,2,3,4 };
	list<int> lst2, lst3, lst4;

	copy(lst1.cbegin(), lst1.cend(), front_inserter(lst2));    // { 4,3,2,1 }
	copy(lst1.cbegin(), lst1.cend(), inserter(lst3, lst3.begin()));    // { 1,2,3,4 }
	copy(lst1.cbegin(), lst1.cend(), back_inserter(lst4));    // { 1,2,3,4 }
	for (auto& i : lst2)
		cout << i << " ";
	cout << endl;
	for (auto& i : lst3)
		cout << i << " ";
	cout << endl;
	for (auto& i : lst4)
		cout << i << " ";
	cout << endl;

    // 输入输出流迭代器
	/* istream_iterator<int> cin_iter(cin);
	istream_iterator<int> endofcin;
	vector<int> v10;
	while (cin_iter != endofcin)
	{
		v10.push_back(*cin_iter++);
	}
	for (auto& i : v10)
		cout << i << " ";
	cout << endl; */

	// 更精简版：用cin迭代器构造vector
	/* istream_iterator<int> cin_iter2(cin), endofcin2;
	vector<int> v11(cin_iter2, endofcin2);
	for (auto& i : v11)
		cout << i << " ";
	cout << endl; */

	// 动态求和
	istream_iterator<int> cin_iter3(cin), endofcin3;
	cout << accumulate(cin_iter3, endofcin3, 1) << endl;

	// 反向迭代器转正向迭代器： reverse_interator的base成员
	string s1 = "1,2,3";
	// reverseComma为s1的反向迭代器，不能直接与s1.end()混用
	auto reverseComma = find(s1.crbegin(), s1.crend(), ',');
	// 对reverseComma进行base操作后其指向','的后一个元素
	// 由于生成reverseComma使用的是cr，此处的s1.cend()是必须的，不能用s1.end()
	cout << string(reverseComma.base(), s1.cend()) << endl;

	return 0;
}