# include <iostream>
# include "hello_Cpp.h"
using namespace std;

void reset(int& r)
{
    // ͨ�����ø����ⲿ����
    r = 0;
}

// ��������ʹ�ó������ã��������const string &s��ֻ�ܴ��ݷǳ����ַ�������
// �����ܴ���const����������ֵ�����µ��ã���������Ƴ���������
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

// �������飬����������ʽ�ȼ�
// ���е����ֵ�10��Ч���������޷�֪������Ĵ�С��ֻ�õ�ָ����Ԫ�ص�ָ��
// void print(const int*);
// void print(const int[]);
// void print(const int[10]);

// ʹ��begin��end���ߺ�������ľ��巶Χ
//void print(const int *beg, const int *end)

// ���������βΣ�ע�����űȲ����٣�����ʱά�������͵�һ���֣��������˺�����ʹ�ã�ֻ�ܴ���ά��Ϊ10�����飩
// void print(int (&arr)[10])

// ��ά�����βΣ���������飩��������ʽ�ȼۣ���һά����Ĵ�С��Ȼ�����ԣ���ָ����ʽ����
// *matrix��ָ���һ��10ά�����ָ�룬�ڶ�ά�������С�̶�Ϊ10
// void print(const (*matrix)[10], int rowSize)
// void print(const matrix[][10], int rowSize)

// main��������������ѡ��
// ����prog -d -o ofile data0
// int main(int argc, char *argv[]) {...}
// int main(int argc, char **argv) {...}
// argc����ʾ�������ַ�����������������Ϊ5
// argv����һ��(ָ�����ѡ����Ϣ��C����ַ���ָ���)���飬���һ��ָ��ȷ��ָ��0
// argv[0] = "prog"  ��ָ��һ�����ַ���
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
    reset(rp);    // ֱ�Ӵ���iҲ�ɴﵽ��ͬЧ��
    cout << i << endl;

    char t = 'J';
    const string ss{ "Lebron James" };
    int p = find_char(ss, t);
    if (p != 12)
        cout << "�ַ�" << t << "��λ��" << p << endl;
    else
        cout << "δ�ҵ��ַ�" << t << endl;

    int* ptr = *arrPtr(4);
    cout << *ptr << endl;
    ++ptr;
    cout << *ptr << endl;

    return 0;
}