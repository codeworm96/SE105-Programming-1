/*本道题目的题号是：2
*要求是：编写并运行课程中的样例程序（11.7），并且分析该程序的结构与功能。
*/
#include "punct.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	Punct_stream ps(cin);
	ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~");//note \" means " in string
	ps.case_sensitive(false);

	cout << "please enter words\n";
	vector<string> vs;
	string word;
	while (ps >> word) vs.push_back(word); //read words

	sort(vs.begin(), vs.end());
	for (int i = 0; i < vs.size(); ++i)
		if (i == 0 || vs[i] != vs[i - 1]) cout << vs[i] << endl;
	return 0;
}
//编写Punct_stream类，处理自定义空白符和大小写
//实现对输入文本忽略标点，大小写划分为单词，排序去重后输出