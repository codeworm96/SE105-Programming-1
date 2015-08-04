#include <iostream>
#include "money.h"
#include <vector>

using namespace std;

void test_cons()
{
	cout << "Testing constructor" << endl;
	Money m1;
	Money m2(1, 50);
	Money m3(0, 0);
	Money m4(-1, 50);
	try{
		Money m5(1, -1);
	}
	catch (Money::Invalid){
		cout << "check ok" << endl;
	}
	try{
		Money m6(1, 100);
	}
	catch (Money::Invalid){
		cout << "check ok" << endl;
	}
}
void test_io()
{
	cout << "input/output test" << endl;
	cout << "Format /$(\\d+).(\\d\\d)/ ($123.10)" << endl;
	try{
		Money m;
		cin >> m;
		cout << m << endl;
	}
	catch (Money::Invalid){
		cerr << "invalid money" << endl;
	}
}

void test_add_sub()
{
	cout << "testing add/sub" << endl;
	try{
		Money m1, m2;
		cout << "input m1" << endl;
		cin >> m1;
		cout << "input m2" << endl;
		cin >> m2;
		cout << "m1 + m2:" << m1 + m2 << endl;
		cout << "m1 - m2:" << m1 - m2 << endl;
	}
	catch (Money::Invalid){
		cerr << "Error!" << endl;
	}
}
void test_mul_div()
{
	cout << "testing mul/div" << endl;
	try{
		Money m1;
		double d;
		cout << "input m1" << endl;
		cin >> m1;
		cout << "input a double" << endl;
		cin >> d;
		cout << "m1 * d:" << m1 * d << endl;
		cout << "m1 / d:" << m1 / d << endl;
	}
	catch (Money::Invalid){
		cerr << "Error!" << endl;
	}
}

void test_divide_money()
{
	cout << "testing divide money" << endl;
	try{
		Money m1;
		cout << "input m1" << endl;
		cin >> m1;
		int n;
		cout << "input n" << endl;
		cin >> n;
		vector<Money> vm = divide_money(m1, n);
		for (size_t i = 0; i < vm.size(); ++i){
			cout << vm[i] << ' ';
		}
		cout << endl;
	}
	catch (Money::Invalid){
		cerr << "Error!" << endl;
	}
}
void test_divmm()
{
	cout << "testing money/money" << endl;
	try{
		Money m1, m2;
		cout << "input m1" << endl;
		cin >> m1;
		cout << "input m2" << endl;
		cin >> m2;
		cout << "m1 / m2:" << m1 / m2 << endl;
	}
	catch (Money::Invalid){
		cerr << "Error!" << endl;
	}
}

int main()//test cases
{
	test_cons();
	test_io();
	test_add_sub();
	test_mul_div();
	test_divmm();
	test_divide_money();
	return 0;
}