# include <iostream>
# include "hello_Cpp.h"
using namespace std;

void reset(int& r)
{
    // 通过引用更改外部变量
    r = 0;
}

// 建议更多地使用常量引用，如果不用const string &s，只能传递非常量字符串变量
// 而不能传递const变量及字面值（见下调用），大大限制程序的灵活性
int find_char(const string &s, char c)
{
    decltype(s.size()) posi = 0;
    for (auto& is : s)
    {
        if (is == c)
        {
            posi = posi;
            break;
        }
        posi++;
    }
    return posi;
}

// 传递数组，下面三种形式等价
// 其中第三种的10无效，即函数无法知道数组的大小，只得到指向首元素的指针
// void print(const int*);
// void print(const int[]);
// void print(const int[10]);

// 使用begin和end告诉函数数组的具体范围
//void print(const int *beg, const int *end)

// 数组引用形参（注意括号比不可少），此时维度是类型的一部分，但限制了函数的使用（只能处理维度为10的数组）
// void print(int (&arr)[10])

// 多维数组形参（数组的数组），两种形式等价，第一维数组的大小仍然被忽略，以指针形式传递
// *matrix是指向第一个10维数组的指针，第二维的数组大小固定为10
// void print(const (*matrix)[10], int rowSize)
// void print(const matrix[][10], int rowSize)

// main函数处理命令行选项
// 例：prog -d -o ofile data0
// int main(int argc, char *argv[]) {...}
// int main(int argc, char **argv) {...}
// argc：表示数组中字符串的数量，本例中为5
// argv：是一个(指向包含选项信息的C风格字符串指针的)数组，最后一个指针确保指向0
// argv[0] = "prog"  或指向一个空字符串
// argv[1] = "-d"
// argv[2] = "-o"
// argv[3] = "ofile"
// argv[4] = "data0"
// argv[5] = 0

int odd[] = { 1,3,5,7,9 };
int even[] = { 0,2,4,6,8 };

decltype(odd)* arrPtr(int i)
{
    return (i % 2) ? &odd : &even;
}

int chapter6()
{
    int i = 9, &rp = i;
    cout << i << endl;
    reset(rp);    // 直接传入i也可达到相同效果
    cout << i << endl;

    char t = 'J';
    const string ss{ "Lebron James" };
    int p = find_char(ss, t);
    if (p != 12)
        cout << "字符" << t << "在位置" << p << endl;
    else
        cout << "未找到字符" << t << endl;

    int* ptr = *arrPtr(4);
    cout << *ptr << endl;
    ++ptr;
    cout << *ptr << endl;

    int x = 9;
    int* const a = &x;
    *a = 11;

    // 函数重载
    // 无法区分顶层const和没有顶层const的形参（本身是const，但指向的对象不一定是const）
    // int look(int);
    // int look(const int);    重复定义
    // int look(int*);
    // int look(int* const);    重复定义

    // 可以区分底层const和没有底层const的形参（指向常量和非常量，区分明确）
    // （虽然底层const也可指向非常量，复习：但不能通过底层const改变所指对象的值）
    // int look(int&);
    // int look(const int&);
    // int look(int*);
    // int look(const int *);

    // 内联函数：声明前加上inline关键字，函数调用时在调用点上内联地展开，减小运行函数时的开销
    // 适用情况：规模较小、调用频繁、流程直接

    // constexpr函数：用于常量表达式，返回值和所有形参类型都必须是字面值类型，函数体中有且只有一条return语句
    // constexpr函数被隐式地指定为内联函数
    constexpr int c = cterfunc();
    // 内联函数和constexpr函数通常定义在头文件里

    // 
    if (1)
    {
        cerr << "Error: " << __FILE__ << endl;
    }

    cout << 3 / 2 << endl;
    cout << -42 % 10 << endl;
    cout << -42 / 10 << endl;
    return 0;
}