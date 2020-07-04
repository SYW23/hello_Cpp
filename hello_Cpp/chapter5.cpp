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

    

    system("pause");
    return 0;
}