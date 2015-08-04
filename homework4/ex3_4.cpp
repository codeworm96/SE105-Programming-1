/*本道题目的题号是：3
*要求是：编写一个程序，它可以实现绝对温度转化为华氏温度和华氏温度转换为绝对温度
*/
#include <iostream>
#include <stdexcept>
using namespace std;

const double delta = 273.15;

double ftok(double f)  //converts Fahrenheit to Kelvin
{
	double k = (f-32)*5/9 + delta;
	if (k < 0){//below -273.15
		throw runtime_error("invalid temperature");
	}
	return k;
}
double ktof(double k)  //converts Kelvin to Fahrenheit
{
	if (k < 0){//below -273.15
		throw runtime_error("invalid temperature");
	}
	double f = (k - delta) * 9 / 5 + 32;
	return f;
}
double get_double()//checked input
{
	double x = 0.0;
	while (true){
		cin >> x;
		if (cin){
			return x;
		}
		else{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Try again." << endl;
		}
	}

}
int choose_func() //choose function
{
	int res = 0;
	bool input_success = false;
	while (!input_success){
		cout << "1. converts Fahrenheit to Kelvin" << endl;
		cout << "2. converts Kelvin to Fahrenheit" << endl;
		cout << "Please choose: ";
		double x = 0.0;
		cin >> x;
		if ((!cin) || !(int(x) == x) || (x > 2) || (x < 1)){ //check
			cout << "Error! Try again." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else{
			res = x;
			input_success = true;
		}
	}
	return res;
}
int main()
try{
	int func = 1;
	func = choose_func(); //choose function
	double c = 0.0; //declare input variable
	cout << "Temperature: ";
	c = get_double();//retrieve temperature to input variable
	double k = 0.0;
	if (func == 1){
		k = ftok(c); //convert temperature
	}
	else{
		k = ktof(c);
	}
	if (!(int(k) == k)){
		throw runtime_error("result is not a integer");
	}
	cout << k << endl;//print out temperature
}
catch (runtime_error& e){
	cerr << "Error: " << e.what() << endl;
	return 1;
}
catch (...){
	cerr << "Unknown error." << endl;
	return 2;
}
//结果合理