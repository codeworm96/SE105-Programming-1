/*本道题目的题号是：5
*要求是：编程求 1000 之内的所有完数。所谓完数是指一个数恰好等于它的包括 1 在内的所有不同因子之和。
*例如，6 是完数，因为 6 = 1 = 2 + 3。注：可以自己定一个判断函数判断一个数字是否是完数
*/
#include <iostream>
#include <stdexcept>
using namespace std; 

const int upper_bound = 1000;

bool isPerfect(int x)
{
	if (x <= 0){//check argument
		throw runtime_error("isRerfect() argument is invalid");
	}
	int sum = 0;
	for (int i = 1; i < x; ++i){
		if (x%i == 0){ //i is a factor
			sum += i;
		}
	}
	return (sum == x);//condition
}

int main()
try{
	//no input
	//output
	cout << "Perfect numbers 1~" << upper_bound << endl;
	for (int i = 1; i <= upper_bound; ++i){
		if (isPerfect(i)){// i is a perfect number
			cout << i << endl;
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