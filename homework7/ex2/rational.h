/*������Ŀ������ǣ�2
*Ҫ���ǣ���Ʋ�ʵ��һ��������Rational��
һ������������������ɣ����Ӻͷ�ĸ����5/6��
ΪRational�ඨ��ʵ�ָ�ֵ���ӡ������ˡ���������ж����������������ת����double��ֵ�ĺ�����
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