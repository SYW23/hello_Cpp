# include <iostream>
# include "hello_world.h"
using namespace std;

// ���ļ��ڵ�return_a��������
// int return_a(int a);
// int chapter1to2(int b, int m, int l, int j);

// const������ʼ��
extern const int j = 512;
constexpr int m = 8;
int l = 0;
double b{ 99.9999 };

int main()
{
    // chapter1to2(b, m, l, j);

    // chapter3();

    chapter4();

    return 0;
}