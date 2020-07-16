# include <iostream>
# include "hello_Cpp.h"
# include <vector>
# include <list>
# include <array>
using namespace std;

int chapter9()
{
	vector<int> v1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	vector<int> v2(v1.begin(), v1.begin() + 4);    // ʹ���Ѷ���������������г�ʼ���¶������������������ҿ���
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

	// vector��string��֧��push_front��pop_front
	// ����insert�ķ���ֵ��ָ��λ�÷�������Ԫ�أ�����֤��Զ����Ԫ��ǰ�������Ԫ��
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

	// array��ʼ��������ָ��Ԫ�����ͺ�������С
	array<int, 30> arr;

	return 0;
}