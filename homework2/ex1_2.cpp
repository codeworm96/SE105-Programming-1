/*������Ŀ������ǣ�1-2
*Ҫ���ǣ����벢���пγ��е���������4.6.2��4.6.3�������ҷ����ó������Ҫ���ܡ�	
*/
//ex 4.6.3
//simple dicitionary:list of sorted words
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> words;
	string temp;
	while (cin >> temp)  //read whitespace-separated words
		words.push_back(temp);  //put into vector
	cout << "Number of words: " << words.size() << endl;

	sort(words.begin(), words.end());  //sort "from beginning to end"

	for (int i = 0; i < words.size(); ++i)
		if (i == 0 || words[i - 1] != words[i])  //is this a new word?
			cout << words[i] << "\n";
}
//����һ�鵥�ʣ�����������������ȥ�غ�Ĵ�
