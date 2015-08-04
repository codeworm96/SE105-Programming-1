/*本道题目的题号是：2
*要求是：设计并实现一个有理数Rational。
一个有理数由两部分组成：分子和分母，如5/6。
为Rational类定义实现赋值、加、减、乘、除及相等判定的运算符，并定义转换至double型值的函数。
*/
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational
{
public:
	class out_of_range {};//exception for the fraction cannot handle;
	class zero_denominator {};//exception for the fraction has denominator of zero;
	Rational(int, int);//constructor
	double to_d() const { return double(numerator) / denominator; }//to double
	//setters
	int numer() const { return numerator; }
	int denom() const { return denominator; }
	Rational operator=(const Rational& x)
	{
		numerator = x.numer();
		denominator = x.denom();
		return x;
	}
private:
	int numerator;    //numerator/denominator
	int denominator;  //denominator>0;gcd(numerator,denominator) == 1
	                  //denominator = 1 if numerator == 0
};

long long gcd(long long a, long long b);
std::ostream& operator<<(std::ostream&, const Rational&); //output
//compare
bool operator==(const Rational&, const Rational&);
bool operator!=(const Rational&, const Rational&);
//+ - * /
Rational operator+(const Rational&, const Rational&);
Rational operator-(const Rational&, const Rational&);
Rational operator*(const Rational&, const Rational&);
Rational operator/(const Rational&, const Rational&);

#endif //RATIONAL_H