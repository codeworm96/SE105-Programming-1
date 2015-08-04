/*������Ŀ������ǣ�1
*Ҫ���ǣ�����һ���ַ����������䳤�ȡ�������ַ���������������������м���ַ���
*���������ʾ��
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