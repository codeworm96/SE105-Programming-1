/*������Ŀ������ǣ�6
*Ҫ���ǣ���д���������������쳲��������У�Ҳ����˵�����еĿ�ʼ��1  1  2  3  5  8  13  21  34����һ������ǰ������֮�͡��ҳ�int�ܱ�ʾ������쳲���������
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