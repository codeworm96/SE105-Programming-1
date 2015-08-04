/*本道题目的题号是：6
*要求是：编写程序，输出尽量长的斐波那契序列，也就是说，序列的开始是1  1  2  3  5  8  13  21  34，下一个数是前两个数之和。找出int能表示的最大的斐波那契数。
*/
#include <iostream>

using namespace std;

class Too_big{};
int safe_add(int a, int b)
{
	long long sum = (long long)a + (long long)b;//long long addition
	int res = sum;//convert to int
	if (sum == res){
		return res;
	}
	else{
		throw Too_big();//exceed the limit of int
	}
}
int main()
try{
	//no input
	cout << "Fibnacci:" << endl;
	int last = 0;//last fib
	int cur = 1;//current fib
	int tmp;
	//calculate
	try{
		while (true){
			cout << cur << endl;
			tmp = safe_add(last, cur);
			last = cur;
			cur = tmp;
		}
	}
	catch (Too_big){
		cout << "Int limit exceeded." << endl;
		cout << "The largest fibnacci which int can represent is " << cur << endl;
	}
	return 0;
}
catch (...){
	cerr << "Unknown error!" << endl;
	return 1;
}