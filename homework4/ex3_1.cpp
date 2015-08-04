/*本道题目的题号是：3
*要求是：下面的程序是获得摄氏温度值并将其转化为绝对温度。但这些代码有很多错误，找出这些错误，指出并修改它们。
*/
#include <iostream>
using namespace std;

double ctok(double c)  //converts Celsius to Kelvin
{
	double k = c + 273.15;//k should be double
	return k;//not int
}
int main()
{
	double c = 0; //declare input variable
	cin >> c;//not d
	//retrieve temperature to input variable
	double k = ctok(c); //without ""
	//convert temperature
	cout << k << endl;//not Cout
	//print out temperature
}
//不产生错误