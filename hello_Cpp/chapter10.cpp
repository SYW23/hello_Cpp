# include <iostream>
# include "hello_Cpp.h"
# include <vector>
# include <list>
# include <array>
# include <numeric>
# include <iterator>
using namespace std;

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

	for (auto i = last_unique; i != v5.cend(); ++i)
		cout << *i << endl;    // 5667789，可用erase删除重复的元素

	return 0;
}