/*本道题目的题号是：3
*要求是：使用名为“埃拉托斯特尼筛法”的经典方法，编写程序找出 1 到 max 之间的所有素数。你可以通过互联网查找相关资料。
*/
#include <iostream>
#include <vector>
using namespace std;

void gen_prime_list(vector<bool>&);
inline int square(int x)
{
	return x*x;
}
int main()
{
	cout << "This program will list all primes in [1,max]" << endl;
	cout << "Please input the upper bound max:";
	int max = 2;
	cin >> max;//input

	vector<bool> list(max + 1, true);
	gen_prime_list(list);//generate the prime list

	//output
	cout << "Prime list:" << endl;
	for (size_t i = 2; i < list.size(); ++i){
		if (list[i]){
			cout << i << endl;
		}
	}
	return 0;
}

//argument: a vector<bool> with all true
//return: a vector<bool>:list[i]==true if and only if i is a prime 
void gen_prime_list(vector<bool> &list)
{
	if (list.size()>0){
		list[0] = false;
		if (list.size() > 1){
			list[1] = false;
		}// workaround for 1 and 0
		for (size_t i = 2; (i < list.size())&&(square(i)<list.size()); ++i){
			if (list[i]){
				size_t j = i + i;
				while (j < list.size()){
					list[j] = false;//not prime
					j += i;
				}
			}
		}
	}
}
