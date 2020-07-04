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
    string b(6, 'win');  // ֻ���ظ����һ����ĸ
    cout << a << " " << b << endl;

    string c{ "Lebron James" };
    cout << c << endl;    // Lebron James
    cin >> c;    // ¼��ӵ�һ���ǿհ��ַ�����һ���հ�֮ǰ���ַ���
    cout << c << endl;    // Lebron

    cin >> a >> b;    // ¼��ӵ�һ���ǿհ��ַ�����һ���հ�֮ǰ���ַ�������a��b
    cout << a << b << endl;    // LebronJames
    cin.get();    // һ�λ���һ���ַ������з�Ҳ��һ���ַ���

    string d;
    getline(cin, d);
    cout << d << endl;
    getline(cin, d);
    cout << d << endl;
    auto n = d.size();
    cout << n << endl;

    cout << (char)toupper(d[0]) << endl;    // ͷ�ļ�cctype

    // ��Χforѭ��
    for (auto &i : c)    // ����string����ÿ���ַ�����������ÿ��Ԫ�أ�;auto���滻Ϊchar
        cout << (char)toupper(i);
    cout << endl;

    string e{ "Miami Heat" };
    for (int j = 0; j < e.size(); ++j)    // ͨ���±���������string����ÿ��Ԫ��
        e[j] = toupper(e[j]);
    cout << e << endl;

    // vector
    vector<int> v1(10);    // 10��Ԫ�أ���Ϊ0
    vector<int> v2{ 10 };    // 1��Ԫ�أ�ֵΪ10
    vector<int> v3(10, 1);    // 10��Ԫ�أ���Ϊ1
    vector<int> v4{ 10, 1 };    // ����Ԫ�أ�10��1
    // Ҫ�û������б��ʼ��vector������Ҫ�����ں�<>��������ͬ
    vector<string> v5{ 10 };    // 10��stringԪ�أ�Ĭ�ϳ�ʼ��
    vector<string> v6{ "hi" };    // �б��ʼ����ֻ��1��stringԪ��hi
    vector<string> v7{ 10, "hi" };    // 10��Ԫ��
    v7.push_back("hello~~~");
    cout << v7[0] << " " << v7[10] << endl;
    // ע�⣺��Χforѭ���в�����vector�����Ԫ�أ�
    for (auto& v0 : v7)
        cout << v0;
    cout << endl;

    // ������
    // ����ʹ�� != ���� < ��Ϊѭ�������жϵ�ϰ��
    // ע�⣺�κ�һ�ָı�vector�����Ĳ�������push_back����ʹ������ʧЧ��
    for (auto iters = d.begin(); iters != d.end() && !isspace(*iters); ++iters)
        *iters = toupper(*iters);
    cout << d << endl;
    // cbegin��cend���ص���const_iterator���ͣ���ֻ��������
    for (auto iterv = v7.cbegin(); iterv != v7.cend(); ++iterv)
    {
        cout << *iterv << endl;
        cout << (*iterv).empty() << endl;    // *it�����Բ���ű�ʾ�Ƚ�����
        cout << "    " << iterv->empty() << endl;    // (*it).memͬit->mem
    }

    // ���� ���� ����[ά��]��ά�ȱ���ȷ����������ʹ��vector����������ʹ��auto��ȷ������
    int arr1[20];
    constexpr unsigned sz = 10;
    unsigned sz_f = 2;
    int arr2[sz];
    // int arr3[sz_f];    ����sz_f���ǳ������ʽ
    int arr3[5] = { 1, 2, 3 };    // {1, 2, 3, 0, 0}
    int arr4[] = { 1,4,7,0 };    // �Զ�ȷ��ά��Ϊ4
    // ����������ȥ��ʼ����һ�����飬���߽�һ�����鿽����ֵ����һ������

    // �ַ�����
    char ac1[] = { 'C', '+', '+' };    // �б��ʼ�������Զ���ĩβ��ӿ��ַ�
    char ac2[] = { 'C', '+', '+', '\0' };    // ��ʽ��ӿ��ַ�
    char ac3[] = "C++";    // ����ĩβ�Զ���ӿ��ַ�
    // const char ac4[6] = "Lebron";    ���󣺼��Ͽ��ַ��󳬳�ά�ȷ�Χ
    
    int* ap1[10];    // ���10������ָ�������
    int (*ap2)[10];    // ap2ָ��һ������10�����������飨����������⣩
    int (&ap3)[10] = arr2;    // ap3����һ������10������������
    int *(&ap4)[10] = ap1;    // �Ժ���10������ָ������������

    for (auto& ia : arr3)
        cout << ia << endl;

    // ������ָ��
    string as1[] = { "1", "2", "3" };
    string* asp1 = &as1[0];    // ָ�������׸�Ԫ�ص�ָ��
    string* asp2 = as1;    // ͬ�ϣ���Ĭ��ָ��������Ԫ�أ�as1�ȼ���&as1[0]
    auto asp3(as1);    // auto�ƶϳ������ͻ���ָ��as1��Ԫ�ص�ָ�룬as1�ȼ���&as1[0]
    cout << *asp1 << *asp2 << *asp3 << endl;    // 111
    // decltype�ƶϳ�������������
    decltype(as1) as2 = {"4", "5", "6"};    // ά�ȱ���Ϊ3

    // ָ��ĵ���������
    int arr5[9] = { 1,2,3,4,5,6,7,8,9 };
    int* ap5 = arr5;    // ָ��arr��Ԫ��
    ap5 = begin(arr5);    // ͬ�ϣ�ͷ�ļ�iterator
    int* ap_end = &arr5[9];    // ָ��arrβԪ�ص���һλ�ã�����Ψһ�ɳ���ά�������������
    ap_end = end(arr5);    // ͬ��
    for (ap5; ap5 != ap_end; ++ap5)
        cout << *ap5 << endl;

    int arr6[] = { 0,2,4,6,8 };
    int last = *(arr6 + 4);    // ������������arr6ֱ�ӱ�ʾָ������Ԫ�ص�ָ��
    cout << last << endl;
    int* ap6 = &arr6[3];    // ap6ָ���±�Ϊ3��Ԫ��
    int arr6_4 = ap6[1];    // �ȼ���*(ap6 + 1)�����±�Ϊ3+1��Ԫ�أ�ע��˴����������÷�*����arr6_4��һ����������ָ�룩
    cout << *ap6 << " " << arr6_4 << endl;

    // ʹ�������ʼ��vector����
    int arr7[] = { 21,4,5,23,39 };
    vector<int> from_arr(begin(arr7), end(arr7));
    vector<int> sub_arr(arr7 + 1, arr7 + 3);    // ֻȡԭ�����һ���֣�����ҿ���
    for (auto& sa : sub_arr)
        cout << sa << endl;

    return 0;
}