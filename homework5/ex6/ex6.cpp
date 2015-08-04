/*本道题目的题号是：6
*要求是：请使用重载方式实现你自己的 sort 函数，使之能够对 vector 的元素 进行从小到大的排序，需要支持的 vector类型包括 vector<int>、vector<double>、 vector<bool>、vector<string>。注意，不能直接使用库函数 sort，要实现你自己的 sort。
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "sort.h"
#include "input.h"

using namespace std;

int main()
try{
	//input
	int n = 0;
	cout << "Please input the size of vector" << endl;
	checked_input(n);

	//tests

	/*vector<int> v;
	int tmp;*/

	/*vector<double> v;
	double tmp;*/

	/*vector<bool> v;
	bool tmp;*/

	vector<string> v;
	string tmp;

	for (int i = 0; i < n; ++i){
		checked_input(tmp);
		v.push_back(tmp);
	}

	sort::sort(v.begin(), v.end());//sort

	//output
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

