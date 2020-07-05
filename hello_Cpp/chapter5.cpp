# include <iostream>
# include "hello_Cpp.h"
using namespace std;

int chapter5()
{
    int position;
    cout << "输入位置（5、4、3、2、1，Ctrl+Z回车结束）：" << endl;
    while (cin >> position)
    {
        switch (position)
        {
            case 5:
                cout << "波什" << endl;
                break;
            case 4:
                cout << "巴蒂尔" << endl;
                break;
            case 3:
                cout << "詹姆斯" << endl;
                break;
            case 2:
                cout << "韦德" << endl;
                break;
            case 1:
                cout << "查尔莫斯" << endl;
                break;
            default:
                cout << "Taco Tuesday~~~gigigigigigi......" << endl;
                break;
        }
    }
    cin.clear();    // 对cin标志位进行复位

    // try语句块内声明的变量在块外部无法访问，尤其是在catch子句内也无法访问
    int i, j;
    cout << "请输入除数和被除数，以空格隔开：" << endl;
    while (cin >> i >> j) {
        try {
            if (j == 0) {
                throw runtime_error("除数不能为零！");
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
                cout << "已退出" << endl;
                break;
            }
        }
    }

    system("pause");
    return 0;
}