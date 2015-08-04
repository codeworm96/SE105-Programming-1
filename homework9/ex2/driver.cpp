#include "polynomial.h"
#include <iostream>

using namespace std;

int main()
try{
	//test default constructor
	cout << "test default constructor" << endl;
	Polynomial p1;
	p1.output();
	cout << endl;

	//test parameterized constructor
	cout << "test parameterized constructor" << endl;
	double coe[3] = { 1, -2, 3 };
	Polynomial p2(2, coe);
	p2.output();
	cout << endl;

	//test assignment
	cout << "test assignment" << endl;
	Polynomial p3;
	p3 = p2;
	p3.output();
	cout << endl;

	//test self-assignment
	cout << "test self-assignment" << endl;
	p2 = p2;
	p2.output();
	cout << endl;

	//other test
	Polynomial p4;
	cout << "input p3:" << endl;
	p3.input();
	cout << "input p4:" << endl;
	p4.input();
    
	cout << "p3:";
	p3.output();
	cout << endl;
	cout << "p4:";
	p4.output();
	cout << endl;

	cout << "p3+p4:";
	p3.add(p4).output();
	cout << endl;

	cout << "p3-p4:";
	p3.subtract(p4).output();
	cout << endl;

	cout << "p3*p4:";
	p3.multiply(p4).output();
	cout << endl;
	return 0;
}
catch (Polynomial::Error){
	cerr << "Polynomial Error" << endl;
	return 1;
}
catch (...){
	cerr << "Unknown error" << endl;
	return 2;
}