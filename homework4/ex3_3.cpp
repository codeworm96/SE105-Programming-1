/*本道题目的题号是：3
*要求是：给这个程序增加一些功能，使它也可以把绝对温度转化为摄氏温度。
*/
#include <iostream>
#include <stdexcept>
using namespace std;

const double delta = 273.15;

double ctok(double c)  //converts Celsius to Kelvin
{
	double k = c + delta;
	if (k < 0){//below -273.15
		throw runtime_error("invalid temperature");
	}
	return k;
}
double ktoc(double k)  //converts Kelvin to Celsius
{
	if (k < 0){//below -273.15
		throw runtime_error("invalid temperature");
	}
	double c = k - delta;
	return c;
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
		cout << "1. converts Celsius to Kelvin" << endl;
		cout << "2. converts Kelvin to Celsius" << endl;
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
		k = ctok(c); //convert temperature
	}
	else{
		k = ktoc(c);
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