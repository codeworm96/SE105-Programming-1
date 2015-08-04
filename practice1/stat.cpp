/*本道题目的题号是 1
*要求是：编写程序，满足下面条件： 
*1. 找出一组输入数据中最大和最小的数据。 
*2. 在一组数据中出现次数最多的数称为mode，要求输入一组正整数，程序能够找出该组数据的mode。
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> numbers;

int getnum()//read & check
{
	int res = 0;
	string input = "";
	cin >> input;
	if (input.empty()){
		return -1;
	}
	size_t i = 0;
	if (input[0] == '+'){
		if (input.size() == 1){
			return -1;
		}
		else{
			i = 1;
		}
	}//optional '+' for postive integer
	while ((i < input.size()) && ((input[i] <= '9') && (input[i] >= '0'))){
		res *= 10;
		res += (input[i] - '0');
		++i;
	}
	if (i < input.size()){
		res = -1;//invalid character found;-1 stand for invalid datum
	}
	return res;
}
void swap(size_t x, size_t y)
{
	int tmp;
	tmp = numbers[x];
	numbers[x] = numbers[y];
	numbers[y] = tmp;
}
void quick_sort(size_t l, size_t r)//[l,r)
{
	if (l + 1 < r){ //more than one data
		swap(l, (l + r) / 2);
		size_t j = l;
		for (size_t i = l + 1; i < r; ++i){
			if (numbers[i] < numbers[l]){
				++j;
				swap(j, i);
			}
		}// divide to two group (greater than a[l] and less than a[l])
		swap(l, j);
		quick_sort(l, j);
		quick_sort(j + 1, r);// solve the sub-problem
	}
}
int main()
{
	cout << "This program will find the maximum, the minimum and the mode of your input." << endl;
	cout << "Please intput some postive integers (end with 0): ";
	int tmp = 0;
	tmp = getnum();
	while (tmp > 0){
		numbers.push_back(tmp);
		tmp = getnum();
	}
	if (tmp < 0){
		cout << "Invalid input!" << endl;
	}
	else{
		if (numbers.empty()){
			cout << "There must be some postive integers!" << endl;
		}
		else{
			//mission 1
			quick_sort(0, numbers.size());
			cout << "The maximum is " << numbers[numbers.size() - 1] << endl;
			cout << "The minimum is " << numbers[0] << endl; //mission 1 completed;
			cout << endl;

			//mission 2
			vector<int> list; //unique integers
			vector<int> times; //times of their occurring
			list.push_back(numbers[0]);
			times.push_back(1);
			for (size_t i = 1; i < numbers.size(); ++i){
				if (numbers[i] == list[list.size() - 1]){
					times[times.size() - 1]++;
				}
				else{
					list.push_back(numbers[i]);
					times.push_back(1);
				}
			}
			int max = times[0];
			for (size_t i = 1; i < times.size(); ++i){
				if (times[i]>max){
					max = times[i];
				}
			}
			int count = 0;
			for (size_t i = 0; i < times.size(); ++i){
				if (times[i] == max){
					++count;
				}
			}
			//output
			if (count == 1){
				cout << "The mode occurs " << max << " time(s)." << endl;
			}
			else{
				cout << "There are "<<count<<" modes. " << endl;
				cout << "The modes occur " << max << " time(s)." << endl;
			}
			cout << "Mode:";
			for (size_t i = 0; i < times.size(); ++i){
				if (times[i] == max){
					cout <<' '<< list[i];
				}
			}
			cout << endl;//mission 2 completed;
		}
	}
	return 0;
}