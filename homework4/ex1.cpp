/*本道题目的题号是：1
*要求是：输入一个字符串，计算其长度。如果该字符串长度是奇数，则输出中间的字符；
*否则给出提示。
*/
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

char mid_char(const string& s)
{
	if (s.length() % 2){ //odd
		return s[s.length() / 2];//middle character
	}
	else{
		throw runtime_error("the length of the string is even. ");
	}
}
int main()
try{
	//hint
	cout << "The program will calculate the length of a string and the middle character. " << endl;
	//input
	string s = "";
	cout << "Please input a string. " << endl;
	cin >> s;
	//calculate length
	cout << "The length of the string is " << s.length() << endl;
	//middle character
	char ch = mid_char(s);
	cout << "The middle char is " << ch << endl;
	return 0;
}
catch (runtime_error& e){
	cerr << "Error: " << e.what() << endl;
	return 1;
}
catch (...){
	cerr << "Unknown error!" << endl;
	return 2;
}