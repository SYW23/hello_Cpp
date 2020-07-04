// C++预处理器功能之头文件保护符，使头文件只被包含一次
# ifndef SALES_DATA_H    // ifndef指令判断预处理变量是否已定义，如果未定义，继续执行剩下语句直到endif结束
# define SALES_DATA_H    // 定义预处理变量SALES_DATA_H（头文件保护符）
# include <string>
// 头文件不宜包含using namespace声明
struct Sales_data {
	std::string bookNo;
	double pricePerBook = 0.0;
	unsigned int numSold_total = 0;
	double revene = 0.0;
};

# endif