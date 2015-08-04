#include <iostream>
using namespace std;

void swap_v(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void swap_r(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
/*
void swap_cr(const int& a, const int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
*/
int main()
{
	double dx = 7.7;
	double dy = 9.9;
	swap_r(dx, dy);
	cout << dx << dy << endl;
}