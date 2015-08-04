/*本道题目的题号是：6
*要求是：根据上面描述，在已经得知你身份证前 17 位的情况下，定义函数，并计算你的身份证号的最后一位
*/
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

const int mod = 11;
const int length = 17;

char checksum(const vector<int>& id)
{
	int sum = 0;
	//like convert bin to dec
	for (size_t i = 0; i < id.size(); ++i){
		sum += id.at(i);//vector<T>::at throws
		sum *= 2;
		sum %= mod;
	}
	//here sum = 0,1..10
	//solve checksum
	int res = 12 - sum;
	res %= mod;
	if (res == 10){
		return 'X';
	}
	else{
		return char('0' + res);
	}
}

int read_digit()
{
	char ch = 'x';
	cin >> ch;
	if ((!cin) || (ch > '9') || (ch < '0')){//check
		throw runtime_error("invalid input");
	}
	return (ch - '0');
}

int main()
try{
	vector<int> id;
	//input
	cout << "This program will calculate the checksum of id. " << endl;
	cout << "Please input first 17 digits. " << endl;
	for (int i = 0; i < length; ++i){
		id.push_back(read_digit());
	}
	//output
	cout << "The last digit is " << checksum(id) << endl;
	return 0;
}
catch (runtime_error& e){
	cerr << "Error: " << e.what() << endl;
	return 1;
}
catch (...){
	cerr << "Unknown error. " << endl;
	return 2;
}