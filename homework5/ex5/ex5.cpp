/*本道题目的题号是：5
*要求是：尝试用递归函数实现两个矩阵的乘法。允许用户自己输入两个矩阵的数据，程序应该判断两个矩阵是否可以相乘。
*/
#include <iostream>
#include <stdexcept>
#include "matrix.h"
using namespace std;

int main()
try{
	math::Matrix a, b;
	//input
	cout << "Note: For input a matrix ,input number of its row and column first,followed by its elements." << endl;
	cout << "Please input A" << endl;
	cin >> a;
	cout << "Please input B" << endl;
	cin >> b;
	math::Matrix c(a*b);//calculate
	//output
	cout << "A*B=" << endl;
	cout << c;
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
