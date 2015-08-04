/*������Ŀ������ǣ�6
*Ҫ���ǣ���ʹ�����ط�ʽʵ�����Լ��� sort ������ʹ֮�ܹ��� vector ��Ԫ�� ���д�С�����������Ҫ֧�ֵ� vector���Ͱ��� vector<int>��vector<double>�� vector<bool>��vector<string>��ע�⣬����ֱ��ʹ�ÿ⺯�� sort��Ҫʵ�����Լ��� sort��
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

