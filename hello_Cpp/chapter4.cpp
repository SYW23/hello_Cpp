# include <iostream>
# include <string>
# include <cctype>
# include <vector>
# include <iterator>
# include <bitset>
# include "hello_Cpp.h"
using namespace std;

int chapter4()
{
    // 需要右值时可用左值代替
    // 但不能把右值当作左值（也就是位置）使用
    // 当一个对象被当做右值使用时（包括左值被当成右值使用时），实际使用的是它的值（内容）
    // 当一个对象被当做左值使用时，实际使用的是它的身份（在内存中的位置）

    /* 要用到左值的运算符：
    赋值运算符需要一个非常量左值作为其左侧运算对象，得到的结果也是一个左值
    取地址符&作用于一个左值运算对象，返回指向该对象的指针，这个指针是右值
    内置解引用运算符、下标运算符、迭代器解引用运算符、string和vector的下标运算符的求值结果都是左值
    内置类型和迭代器的递增递减运算符作用于左值运算对象，其前置版本（++n）结果也是左值
    */ 
    
    // 对于decltype，因为解引用运算符*生成左值，decltype(*p)的结果是int&（假定p是int*）
    // 又因为取地址运算符&生成右值，decltype(&p)的结果是int**，即指向整型指针的指针

    // 除法和取余的结果一律向0取整（即直接切除小数部分）
    // 取余运算 m%n 无视n的符号，只看m的符号
    cout << 78 % 7 << endl;    // 1
    cout << 78 % -7 << endl;    // 1
    cout << -78 % 7 << endl;    // -1
    cout << -78 % -7 << endl;    // -1

    // 递增递减，前置：先运算后赋值；后置：先赋值后运算（基本弃用）
    // ++和--必须作用于左值对象，前置版本将对象本身作为左值返回，后置版本将对象原始值的副本作为右值返回
    int i = 0, j = 0;
    cout << ++i << " " << j++ << endl;

    // 少数情况下用后置版本可使代码更简洁
    vector<int> v1{ 1,7,5,2,0,-3,4 };
    auto pbeg = v1.begin();
    while (pbeg != v1.end() && *pbeg >= 0)
        cout << *pbeg++ << endl;    // 等价于 cout << *pbeg << endl;
                                    //        ++pbeg;

    // 成员访问运算符 . 和 ->
    string s1 = "James", * p1 = &s1;
    auto n = s1.size();
    cout << n << endl;
    n = (*p1).size();
    cout << n << endl;
    n = p1->size();    // (*p).mem 等价于 p->mem 注意括号必须要加，否则指针没有该成员（.运算符优先级更高）
    cout << n << endl;
    // 箭头运算符作用于指针类型对象，结果是一个左值
    // 点运算符，若成员所属对象是左值，结果是左值，反之是右值

    // 条件运算符 ?: （优先级低，用在表达式中一般加括号）
    string ans;
    cout << "LBJ the GOAT? (Yes of No)" << endl;
    cin >> ans;
    string LBJ_is_GOAT = ( ans == "Yes" or ans == "yes" ) ? "Yeah" : "Of course LBJ is the GOAT!";
    cout << LBJ_is_GOAT << endl;
    // 嵌套条件
    int grade;
    string finalgrade;
    cin >> grade;
    finalgrade = ( grade >= 90 ) ? "high pass"
                               : ( grade < 60 ) ? "fail" : "pass";    // 分支
    cout << finalgrade << endl;
    cout << ((grade < 60) ? "fail" : "pass" ) << endl;
    cout << (grade < 60) ? "fail" : "pass";    // 后面不能接endl
    cout << endl;

    // 位运算符
    unsigned char bits = 0227;
    cout << bitset<8>( bits ) << endl;
    cout << bitset<8>( ~bits ) << endl;    // -152
    cout << bitset<8>( bits>>1 ) << endl;    // 75
    cout << sizeof( bits ) << endl;    // 1
    cout << sizeof( ~bits ) << endl;    // 4
    cout << sizeof( bits>>1 ) << endl;    // 4

    // 逗号运算符，从左到右以此计算，左侧表达式的结果求出之后直接丢弃
    // 逗号运算的真正结果是右侧表达式的值，左值右值也视其结果而定
    int a = 9;
    cout << (a + 1, a * 10) << endl;    // 90

    vector<int> v2(10);
    vector<int>::size_type cnt = v2.size();
    for (vector<int>::size_type ix = 0;
        ix != v2.size(); ++ix, --cnt)
        v2[ix] = cnt;
    for (auto& iv : v2)
        cout << iv << endl;

    // const_cast运算符取出底层const特性（未真正去除）
    const int constant = 21;
    const int* const_p = &constant;
    int* modifier = const_cast<int*>(const_p);
    *modifier = 7;    // 通过modifier写值是未定义的行为
    cout << "constant: " << constant << endl;
    cout << "const_p: " << *const_p << endl;
    cout << "modifier: " << *modifier << endl;


    system("pause");
    return 0;
}