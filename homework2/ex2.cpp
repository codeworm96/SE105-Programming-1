/*本道题目的题号是：2
*要求是：定义一个序列的中值恰好是序列的一半元 素在它之前面而另一半元素在它之后的数值，修改 4.6.2 节的程序使其总是能够输 出中值。提示：中值并不一定是序列中的元素。	
*/
//compute mean and median temperatures
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;

int main()
try{
	vector<double> temps; //temperatures
	double temp;
	while (cin >> temp)   //read
		temps.push_back(temp);
	if (temps.empty()){
		throw runtime_error("No temperatures.");
	}

	//compute mean temperature:
	double sum = 0;
	for (int i = 0; i < temps.size(); ++i) sum += temps[i];
	cout << "Average temperature: " << sum / temps.size() << endl;

	//compute median temperature:
	sort(temps.begin(), temps.end()); //sort temps
	//"from the beginning to the end"

	//calculate median
	double median = 0;
	if (temps.size() % 2 == 0){
		median = (temps[temps.size() / 2 - 1] + temps[temps.size() / 2]) / 2;//even: the average of temps[temps.size() / 2 - 1] and temps[temps.size() / 2]
	}
	else{
		median = temps[temps.size() / 2];//odd: temps[temps.size() / 2]
	}
	cout << "Median temperature: " << median << endl;
}
catch (runtime_error& e){
	cerr << "Error: " << e.what() << endl;
	return 1;
}
catch (...){
	cerr << "Unknown error. " << endl;
	return 2;
}