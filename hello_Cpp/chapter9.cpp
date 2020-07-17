# include <iostream>
# include "hello_Cpp.h"
# include <vector>
# include <list>
# include <array>
using namespace std;

int chapter9()
{
	vector<int> v1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	vector<int> v2(v1.begin(), v1.begin() + 4);    // 使用已定义的容器的子序列初始化新定义的容器（区间左闭右开）
	for (auto& i : v1)
	{
		cout << i << " ";
	}
	cout << endl;

	for (auto& i : v2)
	{
		cout << i << " ";
	}
	cout << endl;

	// vector和string不支持push_front和pop_front
	// 利用insert的返回值在指定位置反复插入元素，并保证永远在首元素前面插入新元素
	list<string> lst{ "default" };
	auto beg = lst.begin();
	string word;
	while (cin >> word)
	{
		beg = lst.insert(beg, word);
	}
	for (auto& i : lst)
	{
		cout << i << endl;
	}

	// array初始化：必须指定元素类型和容器大小
	array<int, 30> arr;

	cout << v1.capacity() << endl;    // 现有空间不重新分配的话，能容纳10个元素
	v1.reserve(20);    // 分配20个元素的空间
	cout << v1.capacity() << endl;    // 20
	v1.resize(5);
	cout << v1.capacity() << endl;    // 20，resize不改变内存空间，只改变元素个数


	string s1 = "Lebron James";
	string s2 = s1.substr(6, 3);    // 第二个参数为从起始位置开始计数的长度，即拷贝结尾索引值为6+3-1=8 “ Ja”
	string s3 = s1.substr(6, 100);    // 结尾如果超出范围，只拷贝到末尾，不会报错 “ James”
	cout << s2 << endl;
	cout << s3 << endl;

	return 0;
}