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
	// 定义关联容器的同时可自定义元素排序的方法
	// 注意decltype获得函数指针类型，必须加*
	// 注意用isShorter初始化mset，表示向其添加元素时使用该函数排序
	multiset<string, decltype(isShorter)*> mset(isShorter);
	mset.insert({"hahaha", "haha", "ha", "haha"});
	for (auto& i : mset)
	{
		cout << i << " ";    // ha haha haha hahaha
	}
	cout << endl;

	// map的元素是pair类型
	pair<string, int> times{"eee", 19};
	cout << times.first << " " << times.second << endl;

	// 可通过初始化让pair自动识别类型
	auto x = make_pair(1.22, 9);
	cout << x.first << " " << x.second << endl;

	// 无重复关联容器insert的返回值
	// 返回一个pair，first指向新元素的迭代器，second为一个bool
	// 若关键字已存在，则insert什么也不做（不会用新插入的元素覆盖已有的元素），此时second为false
	// 若关键字不存在，则second为true，插入新元素
	// 可用返回的pair（假设变量名取为ret）的first访问新元素：ret.first->first或ret.first->second

	// 关联容器erase操作的返回值
	// 无重复：返回0或1，0代表没有指定要删除的关键字
	// 可重复：返回0到n，代表删除了的元素个数

	// 可重复的关联容器对于相同关键字的元素采取相邻（连续）存储，可通过迭代器递增递减访问

	// lower指向第一个不小于
	// upper指向第一个大于
	// 若没有匹配的元素，两个都指向该元素可保持元素排序的插入位置（向前插入）
	cout << *mset.lower_bound("haha") << endl;
	cout << *mset.upper_bound("haha") << endl;
	cout << *mset.lower_bound("hah") << endl;
	cout << *mset.upper_bound("hah") << endl;

	return 0;
}