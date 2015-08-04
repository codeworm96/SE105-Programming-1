/*������Ŀ������ǣ�4
*Ҫ���ǣ���д����Ҫ����һ������ n����������ǰ n ��������	
*/
#include <iostream>
#include <vector>
using namespace std;

inline int square(int x)
{
	return x*x;
}
int main()
{
	cout << "This program will print the first to the n-th primes." << endl;
	cout << "Please input n:";
	int n = 1;
	cin >> n;//input
	//generate n primes;
	vector<int> prime_list;
	int i = 2;
	while (prime_list.size() < n){
		bool isPrime = true;
		for (int j = 0; (j < prime_list.size()) && (square(prime_list[j]) <= i); ++j){
			if (i%prime_list[j] == 0){
				isPrime = false;
				break;
			}
		}
		if (isPrime){
			prime_list.push_back(i);//add to prime list
		}
		++i;
	}
	//output
	cout << "Primes:" << endl;
	for (size_t i = 0; i < prime_list.size(); ++i){
		cout << prime_list[i] << endl;
	}
	return 0;
}