// C++Ԥ����������֮ͷ�ļ���������ʹͷ�ļ�ֻ������һ��
# ifndef SALES_DATA_H    // ifndefָ���ж�Ԥ��������Ƿ��Ѷ��壬���δ���壬����ִ��ʣ�����ֱ��endif����
# define SALES_DATA_H    // ����Ԥ�������SALES_DATA_H��ͷ�ļ���������
# include <string>
// ͷ�ļ����˰���using namespace����
struct Sales_data {
	std::string bookNo;
	double pricePerBook = 0.0;
	unsigned int numSold_total = 0;
	double revene = 0.0;
};

# endif