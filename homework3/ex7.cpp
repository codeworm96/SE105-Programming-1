/*������Ŀ������ǣ�7
*Ҫ���ǣ����ö�ά����ʵ�ִ洢 9*9 �˷��ھ�����������ѭ����������Ļ��ӡ����
*/
#include <iostream>
using namespace std;

const int upper_bound = 9;

//generate the multiplication table
void gen_mul_table(int table[][upper_bound])//note:only the first dimension can leave out size
{
	for (int i = 0; i < upper_bound; ++i){
		for (int j = 0; j <= i; ++j){
			table[j][i] = (j + 1)*(i + 1);
		}
	}
}
int main()
try{
	int mul_table[upper_bound][upper_bound];
	gen_mul_table(mul_table);

	//output
	cout << "Multiplication table:" << endl;
	for (int i = 0; i < upper_bound; ++i){
		for (int j = 0; j <= i; ++j){
			cout << j + 1 << '*' << i + 1 << '=' << mul_table[j][i] << ' ';
			if (mul_table[j][i] < 10){
				cout << ' ';//for align
			}
		}
		cout << endl;
	}
	return 0;
}
catch (...){
	cerr << "Unknown error." << endl;
	return 1;
}
