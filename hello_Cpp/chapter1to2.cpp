# include <iostream>
# include "hello_Cpp.h"
# include "Sales_data.h"
using namespace std;

// int return_a(int a);
// int chapter1to2(int b, int m, int l, int j);

int chapter1to2(double b, int m, int l, int j)
{
    cout << "Hello World!" << endl;
    // 对常量的引用必须加上关键字const
    const int& refj = j;
    cout << j  << " " << refj << endl;

    // 不同类型数据的运算
    int a = return_a(9 + b);
    printf("%d\n", a);    // 108
    double c{ 0.01 };
    bool d{ true };
    char e{ 'A' };
    cout << c + d + e << endl;    // 66.01
    // 也可使用常量引用来引用非常量对象，但不可通过常量引用改变对象的值（可用其他方法改变）
    const int& refa = a;
    cout << refa << endl;
    a = 78;
    cout << refa << endl;

    // 观察i的作用域
    int i{ 100 }, sum{ 0 };
    for (int i{ 0 }; i <= 10; ++i)
        sum += i;
    cout << i << " " << sum << endl;    // 100 55

    // 引用
    int f = 1024;
    int& ref = f;    // 引用必须初始化
    cout << ref << endl;    // 定义引用（相当于给一个对象取了一个别名，引用本身非对象）
    ref = 2048;
    cout << ref << endl;
    // int& ref = 10;  // 错误：引用的初始值必须是一个对象而非其它，如字面值常量

    // 指针
    int* p = &f;    // &在表达式中表示取地址，取出变量f的内存地址，赋给指针p
    int** pp = &p;    // 指向指针的指针
    cout << p << " " << pp << endl;    // 指针p指向的内存地址，指针pp为指针p对象的内存地址
    // 使用解引用符*访问指针p所指向的内存地址中存储的数据
    cout << *p << " " << *pp << " " << **pp << endl;    // *pp相当于p，即解得指针p指向的地址，要用指针pp取得f的值需要使用两次解引用符*
    int* p1 = 0;    // 初始化空指针，即没有指向任何对象
    if (p)
        cout << "not void pointer" << endl;
    if (not p1)
        cout << "void pointer" << endl;
    double g = 1.01;
    void* p2 = &g;
    cout << p2 << endl;
    // cout << *p2 << endl;    // 不能直接操作void*指针所指的对象，因其类型不确定

    // 变量的定义包含一个基本数据类型（如int）和一组声明符，而表示指针和引用的*和&其实是声明符的一部分
    int ii = 1024, * ppp = &ii, & rr = ii;    // 一条语句定义多类型的变量
    int* pp1, pp2;    // p1为指针变量，p2为int类型的变量

    // 对指针的引用
    int h = 32;
    int* p3;
    // 离变量名最近的符号影响最大，因此ref1是一个对指针的引用
    int*& ref1 = p3;    // 阅读复杂的声明语句，从右往左读：引用、指针的引用、int类型的指针的引用
    // cout << *ref1 << endl;    // 此时指针p3未初始化，如对ref1使用解引用符将报错
    ref1 = &h;    // 适用指针的引用ref1让指针p3指向变量h
    cout << ref1 << " " << *ref1 << endl;
    p3 = &h;
    cout << p3 << " " << *p3 << endl;    // 和上一个cout语句结果相同
    *ref1 = 64;    // 使用解引用符将变量h的值改为64
    cout << ref1 << " " << *ref1 << endl;

    int k = 2;
    // 左边的const表示（底层const）：指针指向整型常量(也可非整型)，右边的const表示（顶层const）：指针为常量
    const int* const pc = &k;
    cout << pc << " " << *pc << endl;
    // *pc = &h;    不能修改常量指针的地址值
    // *pc = 9;    也不能通过const指针修改所指对象的值，但可以通过对k赋值更改（如果所指的是非常量）
    k = 4;
    cout << k << " " << pc << " " << *pc << endl;


    // constexpr在声明中如果定义了一个指针，仅对指针有效，对指针所指的对象无效
    // constexpr指针的初始值必须是mullptr或0或存储于某个固定地址中的对象
    const int* cp1 = nullptr;    // 一个指向整型常量的指针
    constexpr int* cp2 = nullptr;    // 一个指向整数的常量指针
    constexpr int* cp3 = cp2;    // constexpr定义的指针必须用constexpr定义的常量（包括指针）来初始化
    
    // m和l一般必须定义在函数体之外
    constexpr const int* cp4 = &m;    // cp4是常量指针，指向整型常量，m可以替换成l
    // constexpr int* cp4 = k;    一般情况下，不能用定义在函数体之内的变量初始化constexpr指针
    constexpr int* cp5 = &l;    // cp5是常量指针，这里l不能替换成m

    // 类型别名和指针
    typedef char* pstring;    // 定义一个char*类型的别名，pstring的基本类型是指针
    const pstring cstr = 0;    // cstr是指向char的常量指针（将pstring直接替换为char*再去理解的做法是错误的）
                               // const的作用对象是pstring（基本类型是指针），因此cstr是指向char的常量指针
    const pstring* ps;    // ps是一个指针，其对象为指向char的常量指针

    // auto自动忽略顶层const的特性
    const int a0 = i, & r0 = a0;    // a0不可变，是一个顶层const
    auto b0 = a0;    // b0为普通int
    auto c0 = r0;    // c0为普通int
    auto d0 = &i;    // d0为整型指针
    auto e0 = &r0;    // e0为指向整型常量的指针（对常量对象取地址是底层const，即const int* e0 = &r0）
    const auto f0 = &a0;    // 如果要auto推断出顶层const需要明确指出
    // auto定义引用时，顶层const特性保留
    auto& g0 = a0;    // g0是整型常量引用
    // auto& h0 = 42;    报错：不能给非常量引用绑定字面值
    const auto& h0 = 42;    // 必须声明const给引用绑定字面值

    // decltype
    int n = 3, * p4 = &n, & ref2 = n;
    decltype(n + 0) o;    // o是一个int
    decltype(*p4) q = n;    // q是一个引用，必须初始化
    decltype((n)) s = n;    // 当decltype的括号中再加一个括号，s是一个引用，必须加括号

    /* Sales_data book1, book2;
    unsigned int numSold_once;
    cin >> book1.bookNo >> book1.pricePerBook >> numSold_once;
    book1.numSold_total += numSold_once;
    book1.revene += numSold_once * book1.pricePerBook; */

    m = 9;
    cout << m << endl;

    system("pause");
    return 0;
}
/*
    多行注释不能嵌套
*/


