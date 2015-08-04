/*本道题目的题号是：4
*要求是：读入 5 个名字，存入一个 vector<string>型向量 name，然后提示用户输入这些人的年龄，存入一个 vector<double> 型向量 age 。
然后打印 5 对 （name[i],age[i]）。然后对名字排序（sort(name.begin(),name.end())），并输出（name[i],age[i]）对
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