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
    // ��Ҫ��ֵʱ������ֵ����
    // �����ܰ���ֵ������ֵ��Ҳ����λ�ã�ʹ��
    // ��һ�����󱻵�����ֵʹ��ʱ��������ֵ��������ֵʹ��ʱ����ʵ��ʹ�õ�������ֵ�����ݣ�
    // ��һ�����󱻵�����ֵʹ��ʱ��ʵ��ʹ�õ���������ݣ����ڴ��е�λ�ã�

    /* Ҫ�õ���ֵ���������
    ��ֵ�������Ҫһ���ǳ�����ֵ��Ϊ�����������󣬵õ��Ľ��Ҳ��һ����ֵ
    ȡ��ַ��&������һ����ֵ������󣬷���ָ��ö����ָ�룬���ָ������ֵ
    ���ý�������������±���������������������������string��vector���±����������ֵ���������ֵ
    �������ͺ͵������ĵ����ݼ��������������ֵ���������ǰ�ð汾��++n�����Ҳ����ֵ
    */ 
    
    // ����decltype����Ϊ�����������*������ֵ��decltype(*p)�Ľ����int&���ٶ�p��int*��
    // ����Ϊȡ��ַ�����&������ֵ��decltype(&p)�Ľ����int**����ָ������ָ���ָ��

    // ������ȡ��Ľ��һ����0ȡ������ֱ���г�С�����֣�
    // ȡ������ m%n ����n�ķ��ţ�ֻ��m�ķ���
    cout << 78 % 7 << endl;    // 1
    cout << 78 % -7 << endl;    // 1
    cout << -78 % 7 << endl;    // -1
    cout << -78 % -7 << endl;    // -1

    // �����ݼ���ǰ�ã��������ֵ�����ã��ȸ�ֵ�����㣨�������ã�
    // ++��--������������ֵ����ǰ�ð汾����������Ϊ��ֵ���أ����ð汾������ԭʼֵ�ĸ�����Ϊ��ֵ����
    int i = 0, j = 0;
    cout << ++i << " " << j++ << endl;

    // ����������ú��ð汾��ʹ��������
    vector<int> v1{ 1,7,5,2,0,-3,4 };
    auto pbeg = v1.begin();
    while (pbeg != v1.end() && *pbeg >= 0)
        cout << *pbeg++ << endl;    // �ȼ��� cout << *pbeg << endl;
                                    //        ++pbeg;

    // ��Ա��������� . �� ->
    string s1 = "James", * p1 = &s1;
    auto n = s1.size();
    cout << n << endl;
    n = (*p1).size();
    cout << n << endl;
    n = p1->size();    // (*p).mem �ȼ��� p->mem ע�����ű���Ҫ�ӣ�����ָ��û�иó�Ա��.��������ȼ����ߣ�
    cout << n << endl;
    // ��ͷ�����������ָ�����Ͷ��󣬽����һ����ֵ
    // �������������Ա������������ֵ���������ֵ����֮����ֵ

    // ��������� ?: �����ȼ��ͣ����ڱ��ʽ��һ������ţ�
    string ans;
    cout << "LBJ the GOAT? (Yes of No)" << endl;
    cin >> ans;
    string LBJ_is_GOAT = ( ans == "Yes" or ans == "yes" ) ? "Yeah" : "Of course LBJ is the GOAT!";
    cout << LBJ_is_GOAT << endl;
    // Ƕ������
    int grade;
    string finalgrade;
    cin >> grade;
    finalgrade = ( grade >= 90 ) ? "high pass"
                               : ( grade < 60 ) ? "fail" : "pass";    // ��֧
    cout << finalgrade << endl;
    cout << ((grade < 60) ? "fail" : "pass" ) << endl;
    cout << (grade < 60) ? "fail" : "pass";    // ���治�ܽ�endl
    cout << endl;

    // λ�����
    unsigned char bits = 0227;
    cout << bitset<8>( bits ) << endl;
    cout << bitset<8>( ~bits ) << endl;    // -152
    cout << bitset<8>( bits>>1 ) << endl;    // 75
    cout << sizeof( bits ) << endl;    // 1
    cout << sizeof( ~bits ) << endl;    // 4
    cout << sizeof( bits>>1 ) << endl;    // 4

    // ������������������Դ˼��㣬�����ʽ�Ľ�����֮��ֱ�Ӷ���
    // �������������������Ҳ���ʽ��ֵ����ֵ��ֵҲ����������
    int a = 9;
    cout << (a + 1, a * 10) << endl;    // 90

    vector<int> v2(10);
    vector<int>::size_type cnt = v2.size();
    for (vector<int>::size_type ix = 0;
        ix != v2.size(); ++ix, --cnt)
        v2[ix] = cnt;
    for (auto& iv : v2)
        cout << iv << endl;

    // const_cast�����ȡ���ײ�const���ԣ�δ����ȥ����
    const int constant = 21;
    const int* const_p = &constant;
    int* modifier = const_cast<int*>(const_p);
    *modifier = 7;    // ͨ��modifierдֵ��δ�������Ϊ
    cout << "constant: " << constant << endl;
    cout << "const_p: " << *const_p << endl;
    cout << "modifier: " << *modifier << endl;


    system("pause");
    return 0;
}