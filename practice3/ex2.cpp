/*本道题目的题号是：2
*要求是：修改程序：使用double而不是int。同时保证vector中临近的数值是不同的，并输出vector中的数值。
*/
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

const double eps = 1e-8;

class End_of_input{};

double checked_input()//read & check
{
	double res = 0.0;
	cin >> res;
	if (!cin){  //read failed
		throw End_of_input();
	}
	return res;
}

int checked_input_int()//read & check
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
				n = checked_input_int();
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
void input2(vector<double>& numbers, int n)
//input numbers
{
	bool input_success = false;
	while (!input_success){
		try{
			cout << "Please input some integers (press '|' to end) :";
			try{
				while (true){
					double t = checked_input();
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
	vector<double> list;
	input2(list, n);
	//save n doubles to a vector
	vector<double> numbers;
	for (int i = 0; i < n; ++i){
		numbers.push_back(list[i]);
	}
	//calculate sum
	double sum = 0;
	for (int i = 0; i < n; ++i){
		sum += numbers[i];
	}
	//output
	cout << "The sum of first " << n << " numbers ( ";
	for (int i = 0; i < n; ++i){
		cout << numbers[i] << ' ';
	}
	cout << ") is " << sum << endl;
	//reduce list
	vector<double> reduced_list;
	for (int i = 0; i < list.size(); ++i){
		if ((i == 0) || !(abs(list[i - 1] - list[i]) < eps)){
			reduced_list.push_back(list[i]);
		}
	}
	//output
	cout << "Reduced list: ";
	for (int i = 0; i < reduced_list.size(); ++i){
		cout << reduced_list[i] << ' ';
	}
	cout << endl;
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