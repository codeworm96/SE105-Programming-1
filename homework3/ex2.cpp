/*本道题目的题号是：2
*要求是：计算 e 的值，其中 e=1+1+1/2+1/3!+…+1/n!+…
*/
#include <iostream>
#include <cmath>
using namespace std;

const double eps = 1e-8;

double iterate()
{
	int fac = 1;//for factorial
	double last = -1;//restore last sum
	double sum = 0;//for sum
	int i = 1;//number of terms
	while(abs(sum-last)>eps){
		last = sum;
		fac *= i;
		sum += (1.0 / fac);
		++i;
	}//calculate
	return sum;
}
int main()
try{
	//no input
	cout << "e=" << iterate() + 1 << endl;//output
	return 0;
}
catch (...){
	cerr << "Unknown error!" << endl;
	return 1;
}