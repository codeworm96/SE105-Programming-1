/*������Ŀ������ǣ�1-1
*Ҫ����:���벢���пγ��е���������4.6.2��4.6.3�������ҷ����ó������Ҫ����
*/
//ex 4.6.2
//compute mean and median temperatures
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	vector<double> temps; //temperatures
	double temp;
	while (cin >> temp)   //read
		temps.push_back(temp);

	//compute mean temperature:
	double sum = 0;
	for (int i = 0; i < temps.size(); ++i) sum += temps[i];
	cout << "Average temperature: " << sum / temps.size() << endl;

	//compute median temperature:
	sort(temps.begin(), temps.end()); //sort temps
	//"from the beginning to the end"
	cout << "Median temperature: " << temps[temps.size() / 2] << endl;
}
//����һ���¶ȣ����������ƽ��ֵ��
//��С�������򣬸���Ϊ����ʱ����м�Ԫ�أ�����Ϊż��ʱ����м��������ϴ��һ��