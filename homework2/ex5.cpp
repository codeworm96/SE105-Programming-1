/*本道题目的题号是：5
*要求是：编程寻找 10000 之内所有的素数，且该数是对称的。所谓对称是指一个数字，倒过来还是该数字。例如，375 不是对称数，因为倒过来变成 573。注：数字最高位不是 0
*/
#include <vector>
#include <iostream>
using namespace std;

const int max = 10000;

void gen_prime_list(vector<bool>&);
bool isSymmetrical(int);
inline int square(int x)
{
	return x*x;
}
int main()
{
	// no input
	cout << "This program will find symmetrical primes not greater than " << max << endl;
	vector<bool> is_prime(max + 1, true);

	gen_prime_list(is_prime);//generate the prime list

	//print
	cout << "List:" << endl;
	for (size_t i = 2; i < is_prime.size(); ++i){
		if (is_prime[i] && isSymmetrical(i)){  //satisfy the condition
			cout << i << endl;
		}
	}
	return 0;
}

//argument: a vector<bool> with all true
//return : a vector<bool>:list[i]==true if and only if i is a prime
void gen_prime_list(vector<bool> &list)
{
	if (list.size()>0){
		list[0] = false;
		if (list.size() > 1){
			list[1] = false;
		}  //workaround for 1 and 0
		for (size_t i = 2; (i < list.size()) && (square(i)<list.size()); ++i){
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
bool isSymmetrical(int x)
{
	static vector<int> digits;// use static to avoid the cost of create a vector at every call
	digits.clear();
	while (x > 0){
		digits.push_back(x % 10);
		x /= 10;
	}//separate the digits
	int i = 0;
	int j = digits.size() - 1;
	while (i < j){
		if (digits[i] != digits[j]){  //compare
			return false;
		}
		++i;
		--j;
	}
	return true;
}
