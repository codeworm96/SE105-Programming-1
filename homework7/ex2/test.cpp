#include "rational.h"
#include <iostream>
using namespace std;
//unit test suite
void test_constructor()
{
	cout << "Test case: test constructor" << endl;
	try{
		Rational f1(1, 0);
	}
	catch (Rational::zero_denominator){
		cout << "Rational error catched.constructor can handle error." << endl;
	}
}
void test_print()
{
	cout << "Test case: test print" << endl;
	cout << Rational(0, 1000) << endl;
	cout << Rational(2, 4) << endl;
	cout << Rational(4, 2) << endl;
	cout << Rational(2, -3) << endl;
	cout << Rational(-2, 3) << endl;
	cout << Rational(-2, -3) << endl;
}

void test_to_d()
{
	cout << "Test case: test_to_d" << endl;
	cout << Rational(5, 6).to_d() << endl;
	cout << Rational(6, 5).to_d() << endl;
	cout << Rational(-2, 3).to_d() << endl;
	cout << Rational(1, -4).to_d() << endl;
}

void test_compare()
{
	cout << "Test case: test_compare" << endl;
	cout << (Rational(0, 1) == Rational(0, -1)) << endl;
	cout << (Rational(20, 40) == Rational(1, 2)) << endl;
	cout << (Rational(-1, 3) == Rational(1, -3)) << endl;
	cout << (Rational(2, 5) != Rational(1, 3)) << endl;
}

void test_assign()
{
	cout << "Test case: test assign" << endl;
	Rational r1(1, 3);
	Rational r2(2, 3);
	r2 = r1;
	cout << (r2 == r1) << endl;
}
void test_add()
{
	cout << "Test case: test add" << endl;
	Rational r1(1, 2);
	Rational r2(1, 6);
	cout << r1 + r2 << endl;
	Rational r3(2000000000, 1);
	try{
		Rational r4 = r3 + r3;
	}
	catch (Rational::out_of_range){
		cout << "out_of_range detected." << endl;
	}
}

void test_sub()
{
	cout << "Test case: test sub" << endl;
	Rational r1(1, 2);
	Rational r2(1, 6);
	cout << r1 - r2 << endl;
}

void test_mul()
{
	cout << "Test case: test mul" << endl;
	Rational r1(2, 3);
	Rational r2(1, 4);
	cout << r1*r2 << endl;
}

void test_div()
{
	cout << "Test case: test div" << endl;
	Rational r1(3, 1);
	Rational r2(1, 4);
	cout << r1 / r2 << endl;
	Rational r3(3, 2);
	Rational r4(1, 4);
	cout << r3 / r4 << endl;
	
}

int main()
{
	test_constructor();
	test_print();
	test_to_d();
	test_compare();
	test_assign();
	test_add();
	test_sub();
	test_mul();
	test_div();
}