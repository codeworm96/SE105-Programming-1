/*本道题目的题号是：1-1
*要求是:输入并运行课程中的样例程序（4.6.2，4.6.3），并且分析该程序的主要功能
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
//读入一组温度，计算输出其平均值。
//从小到大排序，个数为奇数时输出中间元素，个数为偶数时输出中间两个数较大的一个