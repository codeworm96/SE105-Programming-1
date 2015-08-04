/*本道题目的题号是：4
*要求是:改进Money类，加入货币功能（货币类型通过构造函数参数给出）。能够接受浮点型的初值，只要能用
long型准确表示即可。不允许非法操作，如Money*Money这种无意义的操作，但只要你提供了美元（USD）和丹麦克朗（DKK）之间的汇率
就可以支持USD1.23+DKK5.00这样有意义的操作。
*/
#ifndef MONEY_H
#define MONEY_H
#include <iostream>
#include <cmath>
#include <vector>

namespace Cur
{
	const double rate[] = { 1, 5.9413 };//1 USD == rate[X] X
}

class Money
{
public:
	enum Currency { USD, DKK };
	class Invalid{};//for error
	//constructors
	Money() :_cent(0){};//$0.00
	Money(long, long);//init with dollar and cent(0~99)
	Money(long c) :_cent(c){};//init with cent
	Money(double);//init with dollar
	Money(Currency kind, double x);//currency function
	long cent() const { return std::abs(_cent) % 100; }
	long dollar() const { return _cent / 100; }
	//getter
	long get_c() const { return _cent; }
	double convert_to(Currency);
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