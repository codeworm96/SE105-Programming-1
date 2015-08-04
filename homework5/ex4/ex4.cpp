/*������Ŀ������ǣ�4
*Ҫ���ǣ����� 5 �����֣�����һ�� vector<string>������ name��Ȼ����ʾ�û�������Щ�˵����䣬����һ�� vector<double> ������ age ��
Ȼ���ӡ 5 �� ��name[i],age[i]����Ȼ�����������sort(name.begin(),name.end())�����������name[i],age[i]����
*/
#include "input.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
try{
	int n = 5;
	//task 2
	cout << "Please input numbers of names" << endl;
	checked_input(n);
	//input names
	vector<string> name;
	cout << "please input " << n << " names" << endl;
	for (int i = 0; i < n; ++i){
		string tmp;
		checked_input(tmp);
		name.push_back(tmp);
	}
	//input age
	vector<double> age;
	cout << "please input their " << n << " ages" << endl;
	for (int i = 0; i < n; ++i){
		double tmp;
		checked_input(tmp);
		age.push_back(tmp);
	}

	//output
	cout << "before sort:" << endl;
	for (int i = 0; i < n; ++i){
		cout << '(' << name[i] << ',' << age[i] << ')' << endl;
	}

	vector<string> old_name(name);
	vector<double> old_age(age);

	sort(name.begin(), name.end());//sort

    //what if there are same names?
	vector<bool> used(n);//is name used?
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if (!used[j]&&(name[i] == old_name[j])){//find the related age
				age[i] = old_age[j];
				used[j] = true;
				break;
			}
		}
	}

	//output
	cout << "after sort:" << endl;
	for (int i = 0; i < n; ++i){
		cout << '(' << name[i] << ',' << age[i] << ')' << endl;
	}
}
catch (runtime_error& e){
	cerr << "Error: " << e.what() << endl;
	return 1;
}
catch (...){
	cerr << "Unknown error" << endl;
	return 2;
}