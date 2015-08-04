/*本道题目的题号是：2
*要求是：继续扩展上面的题目所写的程序，统计一个C++程序中出现的关键词及其频率。
1.ISO  C++98/03关键字共63个。
2.关键词是大小写敏感的。
*/
//Note: c++11 needed
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <set>
#include "word_analyzer.h"

using namespace std;

void bind_file(ifstream& f)//associate a input file stream with file
{
	while (true){
		//input name
		string name = "";
		cout << "Please input a file name (for input): ";
		cin >> name;
		if (cin.eof()){
			throw std::runtime_error("Unexpected input end.");
		}
		if (cin.bad() || cin.fail()){
			throw std::runtime_error("input stream is not well.");
		}
		//try to open file
		try{
			f.open(name.c_str());
			if (!f){//open fail
				throw std::runtime_error("Can't open file!");
			}
			break;
		}
		catch (std::runtime_error& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			std::cout << "Try again." << std::endl;
			continue;
		}
	}
}

set<string>* create_keyword_set()
{
	set<string>* res = new set < string > ;

	//open file
	ifstream fin("cpp_keyword");
	if (!fin){//check
		throw runtime_error("open cpp_keyword file failed");
	}

	string s;
	while (fin >> s){
		res->insert(s);
	}

	if (!fin.eof()){//check
		throw runtime_error("read cpp_keyword file wrong");
	}

	return res;
}

int get_int()//ensure to input a int
{
	int res = 0;
	while (true){
		if (cin >> res){
			return res;
		}
		if (cin.bad()){
			throw runtime_error("bad stream");
		}
		if (cin.eof()){
			throw runtime_error("unexpected end of input");
		}
		cin.clear();//recover
		cin.ignore(1024, '\n');//skip the line
		cout << "Try again." << endl;
	}
}

int get_int(int low, int high)//input int in [low, high]
{
	int res;
	while (true){
		res = get_int();
		if (res <= high&&res >= low){
			return res;
		}
		cout << "Try again." << endl;
	}
}

int main()
try{
	//load
	Text* doc = nullptr;
	ifstream fin;
	bind_file(fin);
	doc = load_from(fin);
	set<string>* keyword = nullptr;
	keyword = create_keyword_set();
	//set
	cout << "Ordered by:" << endl;
	cout << "0:lexical" << endl;
	cout << "1:lexical reversed" << endl;
	cout << "2:frequency" << endl;
	cout << "3:frequency reversed" << endl;
	Word_analyzer::Order ord = Word_analyzer::Order(get_int(0, 3));
	//analyze
	Word_analyzer analyzer(true,ord,keyword);
	std::vector<Result_term>* res = nullptr;
	res = analyzer.analyze(doc);
	//print
	std::vector<Result_term>::iterator iter = res->begin();
	std::vector<Result_term>::iterator end = res->end();
	cout << "Result:" << endl;
	for (; iter != end; ++iter){
		cout << "Word: " << iter->get_word() << "\tFrequency: " << iter->get_frequency() << endl;
	}
	//dispose memory
	delete doc;
	delete res;
	delete keyword;

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