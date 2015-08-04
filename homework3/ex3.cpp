/*������Ŀ������ǣ�3
*Ҫ���ǣ��������漸�����֣�X1,X2,X3����ֵ������ӡ����ע���Լ����ѭ����ֹ���������������� 1000 �Σ�
*/
#include <iostream>
#include <cmath>

using namespace std;

const double eps = 1e-6;
const double eps3 = 5e-10;//for calc3()
const int least_times = 1000;

double calc1()
{
	int time = 0;
	double last = 0.0;//last product
	double product = 1.0;
	double tmp = 0.0;
	while ((time <= least_times) || (abs(product - last) > eps)){
		last = product;
		tmp = sqrt(2 + tmp);
		product *= (tmp / 2);
		++time;
	}
	return product;
}

double calc2()
{
	int time = 0;
	double last = 0.0;//last product
	double product = 1.0;
	while ((time <= least_times) || (abs(product - last) > eps)){
		++time;
		last = product;
		double d = time;
		double n = time;
		if (time % 2){//odd
			d++;
		}
		else{
			n++;
		}
		product *= (d / n);
	}
	return product;
}

double calc3()
{
	int time = 0;
	double last = -1.0;//last sum
	double sum = 0.0;
	while ((time <= least_times) || (abs(sum - last) > eps3)){
		++time;
		last = sum;
		sum += 1.0 / (time*time);
	}
	return sum;
}

int main()
try{
	//no input
	//X1
	double x1 = 2 / calc1();
	//X2
	double x2 = 2 * calc2();//this one is relatively slow;
	//X3
	double x3 = sqrt(6 * calc3());// sqrt losses accuracy

	//output
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
	cout << "x3=" << x3 << endl;
	return 0;
}catch(...){
	cerr << "Unknown error. " << endl;
	return 1;
}