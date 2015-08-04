/*本道题目的题号是：3
*要求是:设计并实现一个Money类，能进行包含美元和美分、精确到美分的计算，使用四舍五入规则（大于等于0.5美分入，小于0.5
美分舍）。用一个long型成员以美分值表示金额，但输入/输出采用美元和美分的形式，例$123.45，不必考虑金额值超出long型范围
的情况。
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