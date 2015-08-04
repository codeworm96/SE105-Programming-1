/*本道题目的题号是：5
*要求是：如果以下代码片段位于一个完整而正确的程序中，不执行程序，
预测一下这个程序会产生什么样的输出结果？你的预测与程序实际输出相
符么？
*/
/*output:
1
1
2
2
3
2
1
*/
#include <iostream>

using namespace std;

int main()
{
	int x = 1;
	cout << x << endl;
	{
		cout << x << endl;
		int x = 2;
		cout << x << endl;
		{
			cout << x << endl;
			int x = 3;
			cout << x << endl;
		}
		cout << x << endl;
	}
	cout << x << endl;
}