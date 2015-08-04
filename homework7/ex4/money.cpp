#include "money.h"
#include <iostream>
#include <cmath>
#include <vector>

Money::Money(long d, long c)
{
	//check
	if ((c >= 100) || (c < 0)){
		throw Invalid();
	}
	//sign
	if (d >= 0){
		_cent = d * 100 + c;
	}
	else{
		_cent = d * 100 - c;
	}
}

Money::Money(double d)//init with dollar
{
	d *= 100;
	long c = d;
	if (c == d){
		_cent = c;
	}
	else{
		throw Invalid();
	}
}
Money::Money(Currency kind, double x)//currency function
{
	x /= Cur::rate[kind];
	x *= 100;
	long c = x;
	if (c == x){
		_cent = c;
	}
	else{
		throw Invalid();
	}
}

std::ostream& operator<<(std::ostream& os, const Money& m)
{
	os << '$' << m.dollar() << '.' << m.cent() / 10 << m.cent() % 10;  //Format /$(\d+).(\d\d)/ ($123.10)
	return os;
}
std::istream& operator>>(std::istream& is, Money& m)//Format /$(\d+).(\d\d)/ ($123.10)
{
	long d;
	char ch1, ch2, c1, c2;
	is >> ch1 >> d >> ch2 >> c1 >> c2;
	//check
	if (!is){
		return is;
	}
	if (ch1 != '$' || ch2 != '.' || c1 > '9' || c1 < '0' || c2 > '9' || c2 < '0'){
		is.clear(std::ios_base::failbit);
		return is;
	}
	//set
	m = Money(d, (c1 - '0') * 10 + (c2 - '0'));
	return is;
}

Money operator+(const Money& a, const Money& b)
{
	return Money(a.get_c() + b.get_c());
}
Money operator-(const Money& a, const Money& b)
{
	return Money(a.get_c() - b.get_c());
}
Money operator*(const Money& a, double b)
{
	return Money(long(round(a.get_c()*b)));//note:round
}
Money operator/(const Money& a, double b)
{
	if (b == 0){
		throw Money::Invalid();//check
	}
	return Money(long(round(a.get_c()/b)));//note:round
}
double operator/(const Money& a, const Money& b)
{
	if (b.get_c() == 0){
		throw Money::Invalid();//check
	}
	return double(a.get_c()) / b.get_c();
}
//divide money,ensure that there is no money left
std::vector<Money> divide_money(const Money& m, int n)
{
	if (n <= 0){
		throw Money::Invalid();//check
	}
	Money left = m;
	std::vector<Money> res; 
	for (int i = n; i > 0; --i){//each time get some money from left to someone
		Money t = left / double(i);
		res.push_back(t);
		left = left - t;
	}
	return res;
}

double Money::convert_to(Currency c)
{
	return Cur::rate[c] * _cent / 100;
}