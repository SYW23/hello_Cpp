# include <iostream>
# include "hello_Cpp.h"
using namespace std;

int chapter5()
{
    int position;
    cout << "����λ�ã�5��4��3��2��1��Ctrl+Z�س���������" << endl;
    while (cin >> position)
    {
        switch (position)
        {
            case 5:
                cout << "��ʲ" << endl;
                break;
            case 4:
                cout << "�͵ٶ�" << endl;
                break;
            case 3:
                cout << "ղķ˹" << endl;
                break;
            case 2:
                cout << "Τ��" << endl;
                break;
            case 1:
                cout << "���Ī˹" << endl;
                break;
            default:
                cout << "Taco Tuesday~~~gigigigigigi......" << endl;
                break;
        }
    }
    cin.clear();    // ��cin��־λ���и�λ

    // try�����������ı����ڿ��ⲿ�޷����ʣ���������catch�Ӿ���Ҳ�޷�����
    int i, j;
    cout << "����������ͱ��������Կո������" << endl;
    while (cin >> i >> j) {
        try {
            if (j == 0) {
                throw runtime_error("��������Ϊ�㣡");
            }
            else {
                cout << i / j << endl;
            }
        }
        catch (runtime_error err) {
            cout << err.what() << endl;
            cout << "try again? y or n" << endl;
            char t;
            cin >> t;
            if (!t || t == 'n') {
                cout << "���˳�" << endl;
                break;
            }
        }
    }

    system("pause");
    return 0;
}