/*本道题目的题号是：4
*要求是：编程求得所有的水仙花数（narcissus number）。所谓水仙花数是指一个三位数，其各位数字立方和等于该数本身。
*例如，153 = 1^3 + 5^3 + 3^3。注： 可以定义判断函数判断一个数字是否是水仙花数。
*/
#include <iostream>
#include <stdexcept>
using namespace std;

inline int cube(int x)
{
	return x*x*x;
}
bool isNarcissus(int x)
{
	if ((x < 100) || (x >= 1000)){
		throw runtime_error("Not a three-digit number");
	}//check
	//seperate digits
	int y = x;
	int a = y % 10;
	y /= 10;
	int b = y % 10;
	y /= 10;
	int c = y % 10;

	return ((cube(a) + cube(b) + cube(c)) == x);//judge
}

int main()
try{
	//no input
	cout << "All narcissus numbers:" << endl;
	for (int i = 100; i < 1000; ++i){
		if (isNarcissus(i)){
			cout << i << endl;//output
		}
	}
	return 0;
}
catch (runtime_error& e){
	cerr << "Error: " << e.what() << endl;
	return 1;
}
catch (...){
	cerr << "Unknown error" << endl;
	return 2;
}