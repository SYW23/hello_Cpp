# include <iostream>
# include "hello_Cpp.h"
# include "Sales_data.h"
using namespace std;

// int return_a(int a);
// int chapter1to2(int b, int m, int l, int j);

int chapter1to2(double b, int m, int l, int j)
{
    cout << "Hello World!" << endl;
    // �Գ��������ñ�����Ϲؼ���const
    const int& refj = j;
    cout << j  << " " << refj << endl;

    // ��ͬ�������ݵ�����
    int a = return_a(9 + b);
    printf("%d\n", a);    // 108
    double c{ 0.01 };
    bool d{ true };
    char e{ 'A' };
    cout << c + d + e << endl;    // 66.01
    // Ҳ��ʹ�ó������������÷ǳ������󣬵�����ͨ���������øı�����ֵ���������������ı䣩
    const int& refa = a;
    cout << refa << endl;
    a = 78;
    cout << refa << endl;

    // �۲�i��������
    int i{ 100 }, sum{ 0 };
    for (int i{ 0 }; i <= 10; ++i)
        sum += i;
    cout << i << " " << sum << endl;    // 100 55

    // ����
    int f = 1024;
    int& ref = f;    // ���ñ����ʼ��
    cout << ref << endl;    // �������ã��൱�ڸ�һ������ȡ��һ�����������ñ���Ƕ���
    ref = 2048;
    cout << ref << endl;
    // int& ref = 10;  // �������õĳ�ʼֵ������һ���������������������ֵ����

    // ָ��
    int* p = &f;    // &�ڱ��ʽ�б�ʾȡ��ַ��ȡ������f���ڴ��ַ������ָ��p
    int** pp = &p;    // ָ��ָ���ָ��
    cout << p << " " << pp << endl;    // ָ��pָ����ڴ��ַ��ָ��ppΪָ��p������ڴ��ַ
    // ʹ�ý����÷�*����ָ��p��ָ����ڴ��ַ�д洢������
    cout << *p << " " << *pp << " " << **pp << endl;    // *pp�൱��p�������ָ��pָ��ĵ�ַ��Ҫ��ָ��ppȡ��f��ֵ��Ҫʹ�����ν����÷�*
    int* p1 = 0;    // ��ʼ����ָ�룬��û��ָ���κζ���
    if (p)
        cout << "not void pointer" << endl;
    if (not p1)
        cout << "void pointer" << endl;
    double g = 1.01;
    void* p2 = &g;
    cout << p2 << endl;
    // cout << *p2 << endl;    // ����ֱ�Ӳ���void*ָ����ָ�Ķ����������Ͳ�ȷ��

    // �����Ķ������һ�������������ͣ���int����һ��������������ʾָ������õ�*��&��ʵ����������һ����
    int ii = 1024, * ppp = &ii, & rr = ii;    // һ����䶨������͵ı���
    int* pp1, pp2;    // p1Ϊָ�������p2Ϊint���͵ı���

    // ��ָ�������
    int h = 32;
    int* p3;
    // �����������ķ���Ӱ��������ref1��һ����ָ�������
    int*& ref1 = p3;    // �Ķ����ӵ�������䣬��������������á�ָ������á�int���͵�ָ�������
    // cout << *ref1 << endl;    // ��ʱָ��p3δ��ʼ�������ref1ʹ�ý����÷�������
    ref1 = &h;    // ����ָ�������ref1��ָ��p3ָ�����h
    cout << ref1 << " " << *ref1 << endl;
    p3 = &h;
    cout << p3 << " " << *p3 << endl;    // ����һ��cout�������ͬ
    *ref1 = 64;    // ʹ�ý����÷�������h��ֵ��Ϊ64
    cout << ref1 << " " << *ref1 << endl;

    int k = 2;
    // ��ߵ�const��ʾ���ײ�const����ָ��ָ�����ͳ���(Ҳ�ɷ�����)���ұߵ�const��ʾ������const����ָ��Ϊ����
    const int* const pc = &k;
    cout << pc << " " << *pc << endl;
    // *pc = &h;    �����޸ĳ���ָ��ĵ�ֵַ
    // *pc = 9;    Ҳ����ͨ��constָ���޸���ָ�����ֵ��������ͨ����k��ֵ���ģ������ָ���Ƿǳ�����
    k = 4;
    cout << k << " " << pc << " " << *pc << endl;


    // constexpr�����������������һ��ָ�룬����ָ����Ч����ָ����ָ�Ķ�����Ч
    // constexprָ��ĳ�ʼֵ������mullptr��0��洢��ĳ���̶���ַ�еĶ���
    const int* cp1 = nullptr;    // һ��ָ�����ͳ�����ָ��
    constexpr int* cp2 = nullptr;    // һ��ָ�������ĳ���ָ��
    constexpr int* cp3 = cp2;    // constexpr�����ָ�������constexpr����ĳ���������ָ�룩����ʼ��
    
    // m��lһ����붨���ں�����֮��
    constexpr const int* cp4 = &m;    // cp4�ǳ���ָ�룬ָ�����ͳ�����m�����滻��l
    // constexpr int* cp4 = k;    һ������£������ö����ں�����֮�ڵı�����ʼ��constexprָ��
    constexpr int* cp5 = &l;    // cp5�ǳ���ָ�룬����l�����滻��m

    // ���ͱ�����ָ��
    typedef char* pstring;    // ����һ��char*���͵ı�����pstring�Ļ���������ָ��
    const pstring cstr = 0;    // cstr��ָ��char�ĳ���ָ�루��pstringֱ���滻Ϊchar*��ȥ���������Ǵ���ģ�
                               // const�����ö�����pstring������������ָ�룩�����cstr��ָ��char�ĳ���ָ��
    const pstring* ps;    // ps��һ��ָ�룬�����Ϊָ��char�ĳ���ָ��

    // auto�Զ����Զ���const������
    const int a0 = i, & r0 = a0;    // a0���ɱ䣬��һ������const
    auto b0 = a0;    // b0Ϊ��ͨint
    auto c0 = r0;    // c0Ϊ��ͨint
    auto d0 = &i;    // d0Ϊ����ָ��
    auto e0 = &r0;    // e0Ϊָ�����ͳ�����ָ�루�Գ�������ȡ��ַ�ǵײ�const����const int* e0 = &r0��
    const auto f0 = &a0;    // ���Ҫauto�ƶϳ�����const��Ҫ��ȷָ��
    // auto��������ʱ������const���Ա���
    auto& g0 = a0;    // g0�����ͳ�������
    // auto& h0 = 42;    �������ܸ��ǳ������ð�����ֵ
    const auto& h0 = 42;    // ��������const�����ð�����ֵ

    // decltype
    int n = 3, * p4 = &n, & ref2 = n;
    decltype(n + 0) o;    // o��һ��int
    decltype(*p4) q = n;    // q��һ�����ã������ʼ��
    decltype((n)) s = n;    // ��decltype���������ټ�һ�����ţ�s��һ�����ã����������

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
    ����ע�Ͳ���Ƕ��
*/


