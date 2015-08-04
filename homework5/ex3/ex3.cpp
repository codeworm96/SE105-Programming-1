/*������Ŀ������ǣ�3
*Ҫ���ǣ���д������������תһ�� vector<int>	���������е�Ԫ��˳�����磬�� 1��3��5��7��9 ת��Ϊ 9��7��5��3��1����һ����ת��������һ���µ�����������Ԫ��Ϊԭ���������򣬶�ԭ�������ݲ��䡣��һ����ת������ʹ���κ�����������ֱ����ԭ�����з�תԪ��˳��
*/
#include <iostream>
#include <vector>
#include "input.h"

using namespace std;

vector<int> reverse1(const vector<int>& v)
{
	vector<int> res;
	for (int i = v.size() - 1; i >= 0; --i){
		res.push_back(v[i]);
	}
	return res;
}

void reverse2(vector<int>& v)
//some language use ! at the end of an identifier to show a method has ``side effects"
//but here we can't
{
	int i = 0;
	int j = v.size() - 1;
	while (i < j){
		//swap
		int tmp;
		tmp = v[i];
		v[i] = v[j];
		v[j] = tmp;

		++i;
		--j;
	}
}
int main()
try{
	//input
	int n = 0;
	cout << "Please input the length of the vector" << endl;
	checked_input(n);

	vector<int> v;
	for (int i = 0; i < n; ++i){
		int tmp;
		checked_input(tmp);
		v.push_back(tmp);
	}
	//reverse
	vector<int> v2 = reverse1(v);
	reverse2(v);
	//output
	cout << "Result of reverse1" << endl;
	for (int i = 0; i < n; ++i){
		cout << v2[i] << endl;
	}
	cout << "Result of reverse2" << endl;
	for (int i = 0; i < n; ++i){
		cout << v[i] << endl;
	}
	return 0;
}
catch (runtime_error& e){
	cerr << "Error: " << e.what() << endl;
	return 1;
}
catch (...){
	cerr << "Unknown error" << endl;
	return 2;
}