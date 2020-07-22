# include <iostream>
# include "hello_Cpp.h"
# include <vector>
using namespace std;

int chapter12()
{
	// new 与 delete
	// new 在自由空间创造一个指向一个动态分配的无名对象（未初始化（不推荐））
	int* pi = new int;    // 默认初始化，未定义
	string* ps = new string;    // 默认初始化为""
	// 值初始化
	int* pi0 = new int();    // 0
	string* ps0 = new string();    // ""
	// 括号/花括号初始化
	int* pi1 = new int(10);
	string* ps1 = new string(10, '9');
	vector<int>* pv1 = new vector<int>{ 1,2,3,4,5 };
	// auto 自推断类型（须有初始化）
	auto* pi2 = new auto(2);
	auto* ps2 = new auto("LBJ");
	// 动态分配 const对象
	const int* cpi = new const int(999);
	const string* cps = new const string{ "the chosen one" };


	// delete 必须得到一个指针，指针指向动态分配的内存或者是一个空指针（不指向任何内存，不管是否动态分配）
	// const对象不能被改变，但能被delete
	delete pi;delete pi0;delete pi1;delete pi2;delete cpi;
	delete ps;delete ps0;delete ps1;delete ps2;delete cps;
	// 内置指针指向的动态内存必须被显式释放，区别与智能指针。
	// delete 指针是销毁了指针指向的动态内存，而指针仍然存在，变为空悬指针

	// 智能指针与new结合
	shared_ptr<double> spd;
	shared_ptr<int> spi(new int(7));
	// 不能用shared_ptr<int> spi = new int(7)隐式初始化智能指针

	return 0;
}