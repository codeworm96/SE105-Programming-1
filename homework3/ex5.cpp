/*������Ŀ������ǣ�5
*Ҫ���ǣ������ 1000 ֮�ڵ�������������ν������ָһ����ǡ�õ������İ��� 1 ���ڵ����в�ͬ����֮�͡�
*���磬6 ����������Ϊ 6 = 1 = 2 + 3��ע�������Լ���һ���жϺ����ж�һ�������Ƿ�������
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