/*������Ŀ������ǣ�3
*Ҫ���ǣ�����ĳ����ǻ�������¶�ֵ������ת��Ϊ�����¶ȡ�����Щ�����кܶ�����ҳ���Щ����ָ�����޸����ǡ�
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
//����������