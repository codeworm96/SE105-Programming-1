/*������Ŀ������ǣ�1
*Ҫ���ǣ������ 1!+2!+��+12!�������ż򻯳���
*/
#include <iostream>
using namespace std;

long factorial_sum(int n)
{
	int fac = 1;//for factorial
	int sum = 0;//for sum
	for (int i = 1; i <= n; ++i){
		fac *= i;
		sum += fac;
	}//calculate
	return sum;
}
int main()
try{
	//no input
	cout << "1!+2!+...+12!=" << factorial_sum(12) << endl;//output
	return 0;
}
catch (...){
	cerr << "Unknown error!" << endl;
	return 1;
}