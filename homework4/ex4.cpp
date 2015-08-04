/*本道题目的题号是：4
*要求是：编写一个可以解一元二次方程的程序。建立一个可以计算二次方程根的函数。
*/
#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

const long double eps = 1e-15;
const long double eps_out = 1e-6;

struct Root
{
	double long x1;
	double long x2;
};//restore answer

Root solve_equ(long double a, long double b, long double c)
//require : b^2-4ac>0 a!=0 effect: the root of equation
{
	if (abs(a) < eps){
		throw runtime_error("not a quadratic equation");
	}
	long double t = b * b - 4 * a * c;
	if (t + eps< 0){  //long double is not accurate
		throw runtime_error("equation does not have real root");
	}
	t = sqrt(t + eps);
	Root res;
	res.x1 = (-b + t) / (2 * a);
	res.x2 = (-b - t) / (2 * a);
	return res;
}

long double checked_input()
//double input with checking
{
	long double x = 0.0;
	cin >> x;
	if (!cin){
		throw runtime_error("invalid input");
	}
	return x;
}

int main()
try{
	//hint
	cout << "The program will solve ax^2+bx+c=0. " << endl;
	//input, checked
	long double a = 0.0;
	long double b = 0.0;
	long double c = 0.0;
	cout << "Please input a, b and c: ";
	a = checked_input();
	b = checked_input();
	c = checked_input();
	//solve
	Root root;
	root = solve_equ(a, b, c);
	//output
	if (abs(root.x1 - root.x2) < eps_out){
		cout << "The root is " << (root.x1 + root.x2)/2 << endl;//be more accurate
	}
	else{
		cout << "The roots are " << root.x1 << ", " << root.x2 << endl;
	}
	return 0;
}
catch (runtime_error& e){
	cerr << "Error: " << e.what() << endl;
	return 1;
}
catch (...){
	cerr << "Unknown error. " << endl;
	return 2;
}

//use test to check
//test input
//case 1: 0.1 0.1 0.1
//case 2: 0.1 0.6 0.9
//case 3: 0.01 -0.03 -0.1