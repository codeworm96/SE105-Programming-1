/*本道题目的题号是：1
*要求是：编写一个程序，读取一个整数序列，并计算前N个整数之和。它首先询问N
的值，然后读取N个值并存入一个Vector中，再计算前N个值之和。
*/
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class End_of_input{};

int checked_input()//read & check
{
	double tmp = 0.1;
	cin >> tmp;
	if (!cin){  //read failed
		throw End_of_input();
	}
	int res = tmp;
	if (res == tmp){  //integer?
		return res;
	}
	else{
		throw runtime_error("invalid input, not a integer");
	}
}

int input1()
{
	bool input_success = false;
	int n = 0;
	while (!input_success){
		try{
			cout << "Please input the number of value you want to sum up: ";
			try{
				n = checked_input();
			}
			catch (End_of_input){
				//because cin is false, the next if will handle it .Just catch it.
			}
			if ((!cin) || (n <= 0)){
				throw runtime_error("invalid n");
			}
			input_success = true;
		}
		catch (runtime_error& e){
			cerr << "Error: " << e.what() << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Try again." << endl;
		}
	}
	return n;
}
void input2(vector<int>& numbers,int n)
//input numbers
{
	bool input_success = false;
	while (!input_success){
		try{
			cout << "Please input some integers (press '|' to end) :";
			try{
				while (true){
					int t = checked_input();
					numbers.push_back(t);
				}
			}
			catch (End_of_input){//end of input
				cin.clear();
				char c = ' ';
				cin >> c;
				if ((!cin) || (c != '|')){//check end
					throw runtime_error("bad input format");
				}
			}
			if (numbers.size() < n){
				throw runtime_error("not enough integers");
			}
			input_success = true;
		}
		catch (runtime_error& e){
			cerr << "Error: " << e.what() << endl;
			cin.clear();
			cin.ignore(1024, '\n');//skip wrong input
			cout << "Try again." << endl;
			numbers.clear();//init vector for next input
		}
	}
}
int main()
try{
	//input n
	int n = 0;
	n = input1();
	//input numbers
	vector<int> list;
	input2(list,n);
	//save n integers to a vector
	vector<int> numbers;
	for (int i = 0; i < n; ++i){
		numbers.push_back(list[i]);
	}
	//calculate sum
	int sum = 0;
	for (int i = 0; i < n; ++i){
		sum += numbers[i];
	}
	//output
	cout << "The sum of first " << n << " numbers ( ";
	for (int i = 0; i < n; ++i){
		cout << numbers[i] << ' ';
	}
	cout << ") is " << sum << endl;
	return 0;
}
catch (runtime_error& e){
	cerr << "Error: " << e.what() << endl;
	return 1;
}
catch (...){
	cerr << "Unknown error." << endl;
	return 2;
}