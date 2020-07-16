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

	return 0;
}