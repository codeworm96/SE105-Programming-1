/*本道题目的题号是：2
*要求是：输入一个字符串，实现反向输出
*/
#include <iostream>
#include <string>

using namespace std;

string str_reverse(const string& s)
//require: string effect: reversed string
{
	string res = "";
	for (int i = s.size() - 1; i >= 0; --i){
		res = res + s[i];
	}
	return res;
}

int main()
try{
	//hint
	cout << "This program will reverse a string." << endl;
	//input
	string s = "";
	cout << "Input a string: ";
	cin >> s;
	//output
	cout << "Reversed string: " << str_reverse(s) << endl;
	return 0;
}
catch (...){
	cerr << "Unknown error. " << endl;
	return 1;
}