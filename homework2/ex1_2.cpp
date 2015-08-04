/*本道题目的题号是：1-2
*要求是：输入并运行课程中的样例程序（4.6.2，4.6.3），并且分析该程序的主要功能。	
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
//读入一组单词，输出个数，排序，输出去重后的词
