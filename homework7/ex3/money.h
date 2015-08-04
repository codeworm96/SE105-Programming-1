/*������Ŀ������ǣ�3
*Ҫ����:��Ʋ�ʵ��һ��Money�࣬�ܽ��а�����Ԫ�����֡���ȷ�����ֵļ��㣬ʹ������������򣨴��ڵ���0.5�����룬С��0.5
�����ᣩ����һ��long�ͳ�Ա������ֵ��ʾ��������/���������Ԫ�����ֵ���ʽ����$123.45�����ؿ��ǽ��ֵ����long�ͷ�Χ
�������
*/
#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <cmath>
#include <vector>

class Money
{
public:
	class Invalid{};//for error
	//constructors
	Money() :_cent(0){};//$0.00
	Money(long, long);//init with dollar and cent(0~99)
	Money(long c) :_cent(c){};//init with cent
	long cent() const { return std::abs(_cent) % 100; }
	long dollar() const { return _cent / 100; }
	//getter
	long get_c() const { return _cent; }
private:
	long _cent;//cent
};

std::ostream& operator<<(std::ostream& os, const Money& m); //Format / $(\d+).(\d\d)/ ($123.10)
std::istream& operator>>(std::istream& is, Money& m); //Format /$(\d+).(\d\d)/ ($123.10)

// + -
Money operator+(const Money& a, const Money& b);
Money operator-(const Money& a, const Money& b);
// * / :for cases where we calculate total price (total price = price * quantity)
Money operator*(const Money& a, double b);
Money operator/(const Money& a, double b);//not precious
double operator/(const Money& a, const Money& b);
//divide money
std::vector<Money> divide_money(const Money& m, int n);
#endif //MONEY_H