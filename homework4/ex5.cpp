/*������Ŀ������ǣ�5
*Ҫ���ǣ�������´���Ƭ��λ��һ����������ȷ�ĳ����У���ִ�г���
Ԥ��һ�������������ʲô���������������Ԥ�������ʵ�������
��ô��
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