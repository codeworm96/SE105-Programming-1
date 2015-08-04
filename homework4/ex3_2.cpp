/*������Ŀ������ǣ�3
*Ҫ���ǣ�������ϰ������ΰѴ��������ctok()�С�
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
int main()
try{
	double c = 0; //declare input variable
	c = get_double();//retrieve temperature to input variable
	double k = ctok(c); //convert temperature
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