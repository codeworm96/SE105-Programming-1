/*������Ŀ������ǣ�2
*Ҫ���ǣ���д�����пγ��е���������11.7�������ҷ����ó���Ľṹ�빦�ܡ�
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
//��дPunct_stream�࣬�����Զ���հ׷��ʹ�Сд
//ʵ�ֶ������ı����Ա�㣬��Сд����Ϊ���ʣ�����ȥ�غ����