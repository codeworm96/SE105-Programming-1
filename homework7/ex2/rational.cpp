#include "rational.h"
#include <cmath>
#include <iostream>

long long gcd(long long a, long long b)
{
	while (b){       //b != 0
		long long c = a%b;
		a = b;
		b = c;
	}
	return a;
}

int convert_to_int(long long x)//checked convert
{
	int y = x;
	if (x != y){
		throw Rational::out_of_range();
	}
	return y;
}

Rational::Rational(int n, int d) :numerator(n), denominator(d)
{
	//check
	if (denominator == 0){
		throw Rational::zero_denominator();
	}
	if (denominator < 0){
		numerator = -numerator;
		denominator = -denominator; //make denominator > 0
	}
	//reduce
	if (numerator == 0){
		denominator = 1;
	}
	else{
		int g = gcd(std::abs(numerator), std::abs(denominator));
		numerator /= g;
		denominator /= g;
	}
}

std::ostream& operator<<(std::ostream& os, const Rational& f)//output
{
	if (f.denom() == 1){
		os << f.numer();
	}
	else{
		os << f.numer() << '/' << f.denom();
	}
	return os;
}

bool operator==(const Rational& a, const Rational& b)//==
{
	return (a.denom() == b.denom()) && (a.numer() == b.numer());
}

bool operator!=(const Rational& a, const Rational& b)//!=
{
	return !(a == b);
}

Rational operator+(const Rational& a, const Rational& b)
{
	long long new_denom = (long long)(a.denom()) * (long long)(b.denom()) / gcd(a.denom(), b.denom());//lcm
	long long new_numer = (long long)(a.numer())*new_denom / a.denom() + (long long)(b.numer())*new_denom / b.denom();
	return Rational(convert_to_int(new_numer), convert_to_int(new_denom));
}

Rational operator-(const Rational& a, const Rational& b)
{
	long long new_denom = (long long)(a.denom()) * (long long)(b.denom()) / gcd(a.denom(), b.denom());//lcm
	long long new_numer = (long long)(a.numer())*new_denom / a.denom() - (long long)(b.numer())*new_denom / b.denom();
	return Rational(convert_to_int(new_numer), convert_to_int(new_denom));
}
Rational operator*(const Rational& a, const Rational& b)
{
	long long new_denom = (long long)(a.denom()) * (long long)(b.denom());
	long long new_numer = (long long)(a.numer()) * (long long)(b.numer());
	return Rational(convert_to_int(new_numer), convert_to_int(new_denom));
}
Rational operator/(const Rational& a, const Rational& b)
{
	long long new_denom = (long long)(a.denom()) * (long long)(b.numer());
	long long new_numer = (long long)(a.numer()) * (long long)(b.denom());
	return Rational(convert_to_int(new_numer), convert_to_int(new_denom));
}