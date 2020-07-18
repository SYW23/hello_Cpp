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

	cout << v1.capacity() << endl;    // ���пռ䲻���·���Ļ���������10��Ԫ��
	v1.reserve(20);    // ����20��Ԫ�صĿռ�
	cout << v1.capacity() << endl;    // 20
	v1.resize(5);
	cout << v1.capacity() << endl;    // 20��resize���ı��ڴ�ռ䣬ֻ�ı�Ԫ�ظ���


	string s1 = "Lebron James";
	string s2 = s1.substr(6, 3);    // �ڶ�������Ϊ����ʼλ�ÿ�ʼ�����ĳ��ȣ���������β����ֵΪ6+3-1=8
	string s3 = s1.substr(6, 100);    // ��β���������Χ��ֻ������ĩβ�����ᱨ��
	string s4 = s1.substr(6);    // �޵ڶ���������Ĭ��ȡ����β
	cout << s2 << endl;    // �� Ja��
	cout << s3 << endl;    // �� James��
	cout << s4 << endl;    // �� James��
	s1.replace(6, 1, "gigigigigigigige");    // 6��ɾ����ʼλ�� 1:��ɾ���Ӵ����� �������������滻���Ӵ�
	cout << s1 << endl;

	return 0;
}