/*������Ŀ������ǣ�1
*Ҫ���ǣ�дһ��������֪�������µ�n���ַ�����
ͳ������Щ�ַ������ɵľ����е��ʵĸ������ҳ����ֵ�˳����ǰ�ĺ����ĵ��ʣ��Ұ����ǵ�λ���г�����
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include "word_stream.h"

using namespace std;

int main()
try{
	cout << "Input a passage (end with end_of_file in a newline)" << endl;
	Word_stream ws(cin);
	Word word("", Pos(1, 1));
	vector<Word> word_list;
	while (ws >> word){
		word_list.push_back(word);
	}
	if (word_list.size() == 0){
		throw runtime_error("no word");
	}
	else{
		cout << "There are " << word_list.size() << " words." << endl;
	}
	sort(word_list.begin(), word_list.end());
	string min_word = word_list[0].get_word();
	cout << "The minimum word is " << min_word << endl;
	unsigned long i = 0;
	while (i < word_list.size() && word_list[i].get_word() == min_word){
		cout << "Line: " << word_list[i].get_pos().get_line() << "\tWord: " << word_list[i].get_pos().get_word() << endl;
		++i;
	}
	string max_word = word_list[word_list.size() - 1].get_word();
	cout << "The maximum word is " << max_word << endl;
	unsigned long j = word_list.size();
	while (j > 0 && word_list[j - 1].get_word() == max_word){
		--j;
	}
	for (size_t i = j; i < word_list.size(); ++i){
		cout << "Line: " << word_list[i].get_pos().get_line() << "\tWord: " << word_list[i].get_pos().get_word() << endl;
	}
	return 0;
}
catch (runtime_error& e){
	cerr << "Error: " << e.what() << endl;
	return 1;
}
catch (...){
	cerr << "Unknown error" << endl;
	return 2;
}