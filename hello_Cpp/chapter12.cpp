# include <iostream>
# include "hello_Cpp.h"
# include <vector>
using namespace std;

int chapter12()
{
	// new �� delete
	// new �����ɿռ䴴��һ��ָ��һ����̬�������������δ��ʼ�������Ƽ�����
	int* pi = new int;    // Ĭ�ϳ�ʼ����δ����
	string* ps = new string;    // Ĭ�ϳ�ʼ��Ϊ""
	// ֵ��ʼ��
	int* pi0 = new int();    // 0
	string* ps0 = new string();    // ""
	// ����/�����ų�ʼ��
	int* pi1 = new int(10);
	string* ps1 = new string(10, '9');
	vector<int>* pv1 = new vector<int>{ 1,2,3,4,5 };
	// auto ���ƶ����ͣ����г�ʼ����
	auto* pi2 = new auto(2);
	auto* ps2 = new auto("LBJ");
	// ��̬���� const����
	const int* cpi = new const int(999);
	const string* cps = new const string{ "the chosen one" };


	// delete ����õ�һ��ָ�룬ָ��ָ��̬������ڴ������һ����ָ�루��ָ���κ��ڴ棬�����Ƿ�̬���䣩
	// const�����ܱ��ı䣬���ܱ�delete
	delete pi;delete pi0;delete pi1;delete pi2;delete cpi;
	delete ps;delete ps0;delete ps1;delete ps2;delete cps;
	// ����ָ��ָ��Ķ�̬�ڴ���뱻��ʽ�ͷţ�����������ָ�롣
	// delete ָ����������ָ��ָ��Ķ�̬�ڴ棬��ָ����Ȼ���ڣ���Ϊ����ָ��

	// ����ָ����new���
	shared_ptr<double> spd;
	shared_ptr<int> spi(new int(7));
	// ������shared_ptr<int> spi = new int(7)��ʽ��ʼ������ָ��

	return 0;
}