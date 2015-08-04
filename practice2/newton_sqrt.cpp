/*本道题目的题号是：1
*要求是：分别用for/while实现两个计算平方根近似值的函数。
*/
#include <stdexcept>
#include <iostream>
using namespace std;

const double eps = 10e-8;

namespace math{
	inline double abs(double x)
	{
		return ((x < 0) ? (-x) : x);
	}
}
namespace use_for{
	double sqrt(double s, int m){
		//check arguments
		if (!(s > 1)){
			throw runtime_error("Invalid s!");
		}//check s
		if (!(m > 0)){
			throw runtime_error("Invalid m!");
		}//check m
		double p0 = (1 + s) / 2;//decide the initial p0;
		double p;

		//iterate
		for (int n = 1; n <= m; ++n){
			p = (p0 + s / p0) / 2;
			if (math::abs(p - p0) < eps){
				return p;
			}
			else{
				p0 = p;
			}
		}
		throw runtime_error("Method failed");//failed
	}
}

namespace use_while{
	double sqrt(double s, int m){
		//check arguments
		if (!(s > 1)){
			throw runtime_error("Invalid s!");
		}//check s
		if (!(m > 0)){
			throw runtime_error("Invalid m!");
		}//check m
		double p0 = (1 + s) / 2;//decide the initial p0;
		double p;

		//iterate
		int n = 1;
		while(n <= m){
			p = (p0 + s / p0) / 2;
			if (math::abs(p - p0) < eps){
				return p;
			}
			else{
				p0 = p;
			}
			++n;
		}
		throw runtime_error("Method failed");//failed
	}
}

int main()
try{
	//input,need improve ,can't handle all invalid input;
	double s = 0;
	int m = 0;
	cout << "This program will calculate the square root of s. " << endl;
	cout << "Please input s(double,s>1) of which the square root you want to calculate: ";
	cin >> s;
	if (!cin){
		throw runtime_error("Invalid input.");
	}
	cout << "Please input the maximum of iteration times m(postive integer): ";
	cin >> m;
	if (!cin){
		throw runtime_error("Invalid input.");
	}

	//output
	cout << "Result of algrithm using for-statement: " << use_for::sqrt(s, m) << endl;
	cout << "Result of algrithm using while-statement: " << use_while::sqrt(s, m) << endl;
	return 0;
}
catch (runtime_error& e){
	cerr << e.what() << endl;
	return 1;
}
catch (...){
	cerr << "Oops! There are some exceptation. " << endl;
	return 2;
}
