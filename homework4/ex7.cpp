/*本道题目的题号是：7
*要求是：那么请编写程序用递归函数来求斐波那契数
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

int fib_helper(int last, int cur, int x, int n)
//using tail-recursive
{
	if (x == n){
		return cur;
	}else{
		return fib_helper(cur, safe_add(last, cur), x + 1, n);
	}
}

int fib(int n)
{
	return fib_helper(0, 1, 1, n);
}

int main()
try{
	//no input
	cout << "Fibnacci:" << endl;
	//calculate
	int n = 0;
	try{
		while (true){
			++n;
			cout << fib(n) << endl;
		}
	}
	catch (Too_big){
		cout << "Int limit exceeded." << endl;
		cout << "The largest fibnacci which int can represent is " << fib(n-1) << endl;
	}
	return 0;
}
catch (...){
	cerr << "Unknown error!" << endl;
	return 1;
}