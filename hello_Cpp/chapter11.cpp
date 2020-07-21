# include <iostream>
# include "hello_Cpp.h"
# include <map>
# include <set>
# include <unordered_map>
# include <unordered_set>
# include <utility>
using namespace std;

int chapter11()
{
	// �������������ͬʱ���Զ���Ԫ������ķ���
	// ע��decltype��ú���ָ�����ͣ������*
	// ע����isShorter��ʼ��mset����ʾ�������Ԫ��ʱʹ�øú�������
	multiset<string, decltype(isShorter)*> mset(isShorter);
	mset.insert({"hahaha", "haha", "ha", "haha"});
	for (auto& i : mset)
	{
		cout << i << " ";    // ha haha haha hahaha
	}
	cout << endl;

	// map��Ԫ����pair����
	pair<string, int> times{"eee", 19};
	cout << times.first << " " << times.second << endl;

	// ��ͨ����ʼ����pair�Զ�ʶ������
	auto x = make_pair(1.22, 9);
	cout << x.first << " " << x.second << endl;

	// ���ظ���������insert�ķ���ֵ
	// ����һ��pair��firstָ����Ԫ�صĵ�������secondΪһ��bool
	// ���ؼ����Ѵ��ڣ���insertʲôҲ�������������²����Ԫ�ظ������е�Ԫ�أ�����ʱsecondΪfalse
	// ���ؼ��ֲ����ڣ���secondΪtrue��������Ԫ��
	// ���÷��ص�pair�����������ȡΪret����first������Ԫ�أ�ret.first->first��ret.first->second

	// ��������erase�����ķ���ֵ
	// ���ظ�������0��1��0����û��ָ��Ҫɾ���Ĺؼ���
	// ���ظ�������0��n������ɾ���˵�Ԫ�ظ���

	// ���ظ��Ĺ�������������ͬ�ؼ��ֵ�Ԫ�ز�ȡ���ڣ��������洢����ͨ�������������ݼ�����

	// lowerָ���һ����С��
	// upperָ���һ������
	// ��û��ƥ���Ԫ�أ�������ָ���Ԫ�ؿɱ���Ԫ������Ĳ���λ�ã���ǰ���룩
	cout << *mset.lower_bound("haha") << endl;
	cout << *mset.upper_bound("haha") << endl;
	cout << *mset.lower_bound("hah") << endl;
	cout << *mset.upper_bound("hah") << endl;

	return 0;
}