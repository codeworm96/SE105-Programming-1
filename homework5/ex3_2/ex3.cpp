/*本道题目的题号是：3
*要求是：对 vector<string>类型向量，重做该习题
*/
#include <iostream>
#include <vector>
#include "input.h"
#include <string>

using namespace std;

vector<string> reverse1(const vector<string>& v)
{
	vector<string> res;
	for (int i = v.size() - 1; i >= 0; --i){
		res.push_back(v[i]);
	}
	return res;
}

void reverse2(vector<string>& v)
//some language use ! at the end of an identifier to show a method has ``side effects"
//but here we can't
{
	int i = 0;
	int j = v.size() - 1;
	while (i < j){
		//swap
		string tmp;
		tmp = v[i];
		v[i] = v[j];
		v[j] = tmp;

		++i;
		--j;
	}
}
int main()
try{
	//input
	int n = 0;
	cout << "Please input the length of the vector" << endl;
	checked_input(n);

	vector<string> v;
	for (int i = 0; i < n; ++i){
		string tmp;
		checked_input(tmp);
		v.push_back(tmp);
	}
	//reverse
	vector<string> v2 = reverse1(v);
	reverse2(v);
	//output
	cout << "Result of reverse1" << endl;
	for (int i = 0; i < n; ++i){
		cout << v2[i] << endl;
	}
	cout << "Result of reverse2" << endl;
	for (int i = 0; i < n; ++i){
		cout << v[i] << endl;
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