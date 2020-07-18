# include <iostream>
# include "hello_Cpp.h"
# include <vector>
# include <list>
# include <array>
# include <numeric>
# include <iterator>
using namespace std;

int chapter10()
{
	vector<int> v1 = { 1,2,3,4,5,6,7,8,9 };
	vector<string> v2 = { "Lebron","James","is","the","GOAT","!!!" };

	// accumulate��������ֵvector�����
	int sum1 = accumulate(v1.cbegin(), v1.cend(), 0);
	// �����ַ���������
	// ��ʾ����string("")�����Ϊ�մ�""������ԭ������""��const char*���ͣ�������û�������+
	string sum2 = accumulate(v2.cbegin(), v2.cend(), string(""));
	cout << sum1 << endl;
	cout << sum2 << endl;

	// fill��fill_n
	fill(v1.begin(), v1.end(), 0);    // ������Ԫ������Ϊ0
	fill_n(v1.begin(), v1.size(), 0);    // ����һ��ȼ�
	vector<int> v3;    // ������
	// ����back_inserter�����������β���10��3
	fill_n(back_inserter(v3), 10, 3);
	// �ȼ���
	// auto it = back_inserter(v3);
	// for (int i = 0; i < 10; ++i)
	//     *it = 3;
	for (auto& i : v3)
		cout << i << endl;

	// replace ������3�滻Ϊ33
	replace(v3.begin(), v3.end(), 3, 33);
	for (auto& i : v3)
		cout << i << endl;

	vector<int> v4;
	// replace_copy ���滻���������������һ��������ԭ�������ֲ���
	replace_copy(v3.cbegin(), v3.cend(), back_inserter(v4), 33, 5);
	for (auto& i : v4)
		cout << i << endl;

	// sort��unique
	vector<int> v5 = { 9,3,3,1,5,6,7,8,2,2,3,5,4,4,7,6 };
	sort(v5.begin(), v5.end());    // ����
	for (auto& i : v5)
		cout << i << endl;    // 1223334455667789
	auto last_unique = unique(v5.begin(), v5.end());    // �����ظ���Ԫ�ط���ǰ�棬�ظ������ں���
	for (auto& i : v5)
		cout << i << endl;    // 1234567895667789 ע����sort�Ľ���Աȣ�Ԫ�ط����˱仯
	cout << endl;

	for (auto i = last_unique; i != v5.cend(); ++i)
		cout << *i << endl;    // 5667789������eraseɾ���ظ���Ԫ��

	return 0;
}