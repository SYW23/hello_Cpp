# include <iostream>
# include <string>
# include <cctype>
# include <vector>
# include <iterator>
# include "hello_world.h"
using namespace std;

int chapter3()
{
    // string
    string a{ "Lebron" };
    string b(6, 'win');  // 只会重复最后一个字母
    cout << a << " " << b << endl;

    string c{ "Lebron James" };
    cout << c << endl;    // Lebron James
    cin >> c;    // 录入从第一个非空白字符到下一处空白之前的字符串
    cout << c << endl;    // Lebron

    cin >> a >> b;    // 录入从第一个非空白字符到下一处空白之前的字符串，先a后b
    cout << a << b << endl;    // LebronJames
    cin.get();    // 一次回收一个字符（换行符也算一个字符）

    string d;
    getline(cin, d);
    cout << d << endl;
    getline(cin, d);
    cout << d << endl;
    auto n = d.size();
    cout << n << endl;

    cout << (char)toupper(d[0]) << endl;    // 头文件cctype

    // 范围for循环
    for (auto &i : c)    // 遍历string对象每个字符（遍历序列每个元素）;auto可替换为char
        cout << (char)toupper(i);
    cout << endl;

    string e{ "Miami Heat" };
    for (int j = 0; j < e.size(); ++j)    // 通过下标索引遍历string对象每个元素
        e[j] = toupper(e[j]);
    cout << e << endl;

    // vector
    vector<int> v1(10);    // 10个元素，都为0
    vector<int> v2{ 10 };    // 1个元素，值为10
    vector<int> v3(10, 1);    // 10个元素，都为1
    vector<int> v4{ 10, 1 };    // 两个元素，10和1
    // 要用花括号列表初始化vector对象，需要括号内和<>内类型相同
    vector<string> v5{ 10 };    // 10个string元素，默认初始化
    vector<string> v6{ "hi" };    // 列表初始化，只有1个string元素hi
    vector<string> v7{ 10, "hi" };    // 10个元素
    v7.push_back("hello~~~");
    cout << v7[0] << " " << v7[10] << endl;
    // 注意：范围for循环中不能向vector中添加元素！
    for (auto& v0 : v7)
        cout << v0;
    cout << endl;

    // 迭代器
    // 养成使用 != 而非 < 作为循环结束判断的习惯
    // 注意：任何一种改变vector容量的操作（如push_back）会使迭代器失效！
    for (auto iters = d.begin(); iters != d.end() && !isspace(*iters); ++iters)
        *iters = toupper(*iters);
    cout << d << endl;
    // cbegin和cend返回的是const_iterator类型，即只读迭代器
    for (auto iterv = v7.cbegin(); iterv != v7.cend(); ++iterv)
    {
        cout << *iterv << endl;
        cout << (*iterv).empty() << endl;    // *it必须加圆括号表示先解引用
        cout << "    " << iterv->empty() << endl;    // (*it).mem同it->mem
    }

    // 数组 类型 名称[维度]（维度必须确定，否则需使用vector），不允许使用auto来确定类型
    int arr1[20];
    constexpr unsigned sz = 10;
    unsigned sz_f = 2;
    int arr2[sz];
    // int arr3[sz_f];    错误：sz_f不是常量表达式
    int arr3[5] = { 1, 2, 3 };    // {1, 2, 3, 0, 0}
    int arr4[] = { 1,4,7,0 };    // 自动确定维度为4
    // 不能用数组去初始化另一组数组，或者将一个数组拷贝赋值给另一个数组

    // 字符数组
    char ac1[] = { 'C', '+', '+' };    // 列表初始化：不自动在末尾添加空字符
    char ac2[] = { 'C', '+', '+', '\0' };    // 显式添加空字符
    char ac3[] = "C++";    // 将在末尾自动添加空字符
    // const char ac4[6] = "Lebron";    错误：加上空字符后超出维度范围
    
    int* ap1[10];    // 存放10个整型指针的数组
    int (*ap2)[10];    // ap2指向一个含有10个整数的数组（由内向外理解）
    int (&ap3)[10] = arr2;    // ap3引用一个含有10个整数的数组
    int *(&ap4)[10] = ap1;    // 对含有10个整型指针的数组的引用

    for (auto& ia : arr3)
        cout << ia << endl;

    // 数组与指针
    string as1[] = { "1", "2", "3" };
    string* asp1 = &as1[0];    // 指向数组首个元素的指针
    string* asp2 = as1;    // 同上，即默认指向数组首元素，as1等价于&as1[0]
    auto asp3(as1);    // auto推断出的类型还是指向as1首元素的指针，as1等价于&as1[0]
    cout << *asp1 << *asp2 << *asp3 << endl;    // 111
    // decltype推断出的类型是数组
    decltype(as1) as2 = {"4", "5", "6"};    // 维度必须为3

    // 指针的迭代器特性
    int arr5[9] = { 1,2,3,4,5,6,7,8,9 };
    int* ap5 = arr5;    // 指向arr首元素
    ap5 = begin(arr5);    // 同上，头文件iterator
    int* ap_end = &arr5[9];    // 指向arr尾元素的下一位置（数组唯一可超出维度索引的情况）
    ap_end = end(arr5);    // 同上
    for (ap5; ap5 != ap_end; ++ap5)
        cout << *ap5 << endl;

    int arr6[] = { 0,2,4,6,8 };
    int last = *(arr6 + 4);    // 这里数组名称arr6直接表示指向其首元素的指针
    cout << last << endl;
    int* ap6 = &arr6[3];    // ap6指向下标为3的元素
    int arr6_4 = ap6[1];    // 等价于*(ap6 + 1)，即下标为3+1的元素（注意此处包含解引用符*，即arr6_4是一个整数而非指针）
    cout << *ap6 << " " << arr6_4 << endl;

    // 使用数组初始化vector对象
    int arr7[] = { 21,4,5,23,39 };
    vector<int> from_arr(begin(arr7), end(arr7));
    vector<int> sub_arr(arr7 + 1, arr7 + 3);    // 只取原数组的一部分（左闭右开）
    for (auto& sa : sub_arr)
        cout << sa << endl;

    return 0;
}