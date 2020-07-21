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
	auto f = [x1] { return x1; };    // ֵ���񣨼�������
	x1 = 0;
	cout << f() << endl;
}

void fc2()
{
	size_t x1 = 39;
	auto f = [&x1] { return x1; };    // ���ò����뱣֤lambdaִ��ʱ�ñ�������
	x1 = 0;
	cout << f() << endl;
}

int chapter10()
{
	vector<int> v1 = { 1,2,3,4,5,6,7,8,9 };
	vector<string> v2 = { "Lebron","James","is","the","GOAT","!!!" };

	// accumulate��������ֵvector�����
	int sum1 = accumulate(v1.cbegin(), v1.cend(), 0);
	// �����ַ���������
	// ��ʾ����string("")�����Ϊ�մ�""������ԭ������""��const char*���ͣ�������û�������+
	string sum2 = accumulate(v2.cbegin(), v2.cend(), string(""));
	cout << sum1 << endl;
	cout << sum2 << endl;

	// fill��fill_n
	fill(v1.begin(), v1.end(), 0);    // ������Ԫ������Ϊ0
	fill_n(v1.begin(), v1.size(), 0);    // ����һ��ȼ�
	vector<int> v3;    // ������
	// ����back_inserter�����������β���10��3
	fill_n(back_inserter(v3), 10, 3);
	// �ȼ���
	// auto it = back_inserter(v3);
	// for (int i = 0; i < 10; ++i)
	//     *it = 3;
	for (auto& i : v3)
		cout << i << endl;

	// replace ������3�滻Ϊ33
	replace(v3.begin(), v3.end(), 3, 33);
	for (auto& i : v3)
		cout << i << endl;

	vector<int> v4;
	// replace_copy ���滻���������������һ��������ԭ�������ֲ���
	replace_copy(v3.cbegin(), v3.cend(), back_inserter(v4), 33, 5);
	for (auto& i : v4)
		cout << i << endl;

	// sort��unique
	vector<int> v5 = { 9,3,3,1,5,6,7,8,2,2,3,5,4,4,7,6 };
	sort(v5.begin(), v5.end());    // ����
	for (auto& i : v5)
		cout << i << endl;    // 1223334455667789
	auto last_unique = unique(v5.begin(), v5.end());    // �����ظ���Ԫ�ط���ǰ�棬�ظ������ں���
	for (auto& i : v5)
		cout << i << endl;    // 1234567895667789 ע����sort�Ľ���Աȣ�Ԫ�ط����˱仯
	cout << endl;
	// unique�ķ���ֵΪָ���һ����ʼ�ظ���Ԫ�صĵ�����
	for (auto i = last_unique; i != v5.cend(); ++i)
		cout << *i << endl;    // 5667789������eraseɾ���ظ���Ԫ��

	cout << endl;
	// ν�ʣ������Զ��庯������
	sort(v5.begin(), v5.end(), mod5);
	for (auto& i : v5)
		cout << i << endl;    // 5516662777388499
	cout << endl;
	// stable_sort �����ͬʱ��������ȵ�Ԫ��ά��ԭ���˳�򲻱�
	vector<int> v6 = { 9,3,3,1,5,6,7,8,2,2,3,5,4,4,7,6 };
	stable_sort(v6.begin(), v6.end(), mod5);
	for (auto& i : v6)
		cout << i << endl;    // 5516672273383944

	// β�÷���
	// auto func(�����б�) -> ��������
	// {
	//     ������
	//  }
	cout << func() << endl;

	cout << endl;
	// lambda [�����б�ʵ�Σ�](�β��б�){������}
	vector<int> v7 = { 9,3,3,1,5,6,7,8,2,2,3,5,4,4,7,6 };
	stable_sort(v7.begin(), v7.end(),
		        [](const int a, const int b)
		            { return a % 5 < b % 5; });
	for (auto& i : v7)
		cout << i << endl;    // 5516672273383944

	// find_if ����ָ���һ������������Ԫ�صĵ�����
	int base = 8;
	auto p = find_if(v7.begin(), v7.end(),
		             [base](const int a)
		                 { return a > base; });
	cout << *p << endl;

	// for_each �Ե�����ָ���ÿ��Ԫ�ص���һ���ɵ��ö���
	for_each(p, v7.end(),
		    [](const int a)
		    { cout << a << " "; });
	cout << endl;


	// lambda ����Ĵ���ʱ����ֵ��������ò���
	fc1();    // 39
	fc2();    // 0

	cout << endl;
	// lambda ��������һ�������˳�return�������䣬�������ٶ��䷵��void
	// �����Ҫ�����ض����͵�ֵ����ʹ��β�÷���ָ��
	vector<int> v8 = { -1,0,3,-9,8,5 };
	transform(v8.begin(), v8.end(), v8.begin(),
		     [](int a) -> int
		     { if (a < 0) return -a; else return a; });
	for (auto& i : v8)
		cout << i << endl;
	cout << endl;

	// �����ַ���������
	vector<string> v9 = { "a", "aa", "aaa", "aaaa" };
	sort(v9.begin(), v9.end(), isShorter);
	for (auto& i : v9)
		cout << i << " ";
	cout << endl;

	v9 = { "a", "aa", "aaa", "aaaa" };
	auto excg_isShorter = bind(isShorter, _2, _1);    // ����bind���Ų���˳��
	sort(v9.begin(), v9.end(), excg_isShorter);    // �൱���������У��������ȴӴ�С
	for (auto& i : v9)
		cout << i << " ";
	cout << endl;

	// ��Ҫ����bind����ostream������Ҫ�������ref����
	// ostream &print(ostream &os, const string &s, char c) { return os << s << c; }
	// for_each(v9.begin(), v9.end(),
	//          bind(print, ref(os), _1, ' '));

	cout << endl;
	// inserter ��ͨ��ǰ�������ڵ�һ��Ԫ��ǰ���룩�������������һ��Ԫ�غ���룩
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

    // ���������������
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

	// ������棺��cin����������vector
	/* istream_iterator<int> cin_iter2(cin), endofcin2;
	vector<int> v11(cin_iter2, endofcin2);
	for (auto& i : v11)
		cout << i << " ";
	cout << endl; */

	// ��̬���
	istream_iterator<int> cin_iter3(cin), endofcin3;
	cout << accumulate(cin_iter3, endofcin3, 1) << endl;

	// ���������ת����������� reverse_interator��base��Ա
	string s1 = "1,2,3";
	// reverseCommaΪs1�ķ��������������ֱ����s1.end()����
	auto reverseComma = find(s1.crbegin(), s1.crend(), ',');
	// ��reverseComma����base��������ָ��','�ĺ�һ��Ԫ��
	// ��������reverseCommaʹ�õ���cr���˴���s1.cend()�Ǳ���ģ�������s1.end()
	cout << string(reverseComma.base(), s1.cend()) << endl;

	return 0;
}