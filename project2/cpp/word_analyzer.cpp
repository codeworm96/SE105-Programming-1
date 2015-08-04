#include <list>
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <algorithm>
#include "word_analyzer.h"

//Text
Text* load_from(std::istream& is)
{
	Text* doc = nullptr;
	doc = new Text;
	std::string s;
	while (std::getline(is, s)){
		doc->push_back(s);
	}

	if (!is.eof()){//check input
		throw std::runtime_error("load failed.");
	}

	return doc;
}

Text* Word_analyzer::chop(Text* doc)//no syntax check!, handle comment and string
{
	if (doc == nullptr){//check
		throw std::runtime_error("text needed.");
	}

	Text* res = new Text;

	//status
	static const int normal = 0;
	static const int single_com = 1;//after //
	static const int in_str = 2;//in " "
	static const int multi_com = 3;//in /* */

	int status = normal;
	Text::iterator iter = doc->begin();
	Text::iterator end = doc->end();
	for (; iter != end; ++iter){
		std::string s = *iter;
		std::string t;
		for (std::string::size_type i = 0; i < s.size(); ++i){
			switch (status){
			case normal:
				if (s[i] == '"'){
					if (i == 0 || s[i - 1] != '\\'){//check for \"
						if (!((i>0) && (i < s.size() - 1) && (s[i - 1] == '\'') && (s[i + 1] == '\''))){//check for '"'
							status = in_str;
							t += ' ';
							break;
						}
					}
				}
				if ((i + 1 < s.size()) && (s[i] == '/')){
					if (s[i + 1] == '/'){
						status = single_com;
						t += ' ';
						break;
					}
					if (s[i + 1] == '*'){
						status = multi_com;
						t += ' ';
						break;
					}
				}
				t += s[i];
				break;
			case in_str:
				if (s[i] == '"'){
					if (i == 0 || s[i - 1] != '\\'){//check for \"
						status = normal;
						break;
					}
				}
				break;
			case multi_com:
				if (s[i] == '/'){
					if ((i > 0) && (s[i - 1] == '*')){
						status = normal;
						break;
					}
				}
				break;
			}
		}
		res->push_back(t);
		if (status == single_com){
			status = normal;
		}
		if (status == in_str){
			if (s[s.size() - 1] != '\\'){
				throw std::runtime_error("syntaxError: \" excepted.");
			}
		}
	}

	return res;
}

std::vector<std::string>* Word_analyzer::split(std::string s)
{
	std::vector<std::string>* res = new std::vector < std::string > ;

	bool in_identifer = false;
	std::string t = "";
	for (std::string::size_type i = 0; i < s.size(); ++i){
		if (in_identifer){
			if (isalnum(s[i]) || (s[i] == '_')){
				t += s[i];
			}
			else{
				res->push_back(t);
				t = "";
				in_identifer = false;
			}
		}
		else{
			if (isalpha(s[i]) || (s[i] == '_')){
				in_identifer = true;
				t = s[i];
			}
		}
	}
	//last identifer
	if (in_identifer){
		res->push_back(t);
	}

	return res;
}

void Word_analyzer::downcase(std::string& s)
{
	for (std::string::size_type i = 0; i < s.size(); ++i){
		s[i] = tolower(s[i]);
	}
}

//comparers
bool lex_cmp(const Result_term& a, const Result_term& b)
{
	return a.get_word() < b.get_word();
}
bool lex_r_cmp(const Result_term& a, const Result_term& b)
{
	return a.get_word() > b.get_word();
}
bool fre_cmp(const Result_term& a, const Result_term& b)
{
	return a.get_frequency() < b.get_frequency();
}
bool fre_r_cmp(const Result_term& a, const Result_term& b)
{
	return a.get_frequency() > b.get_frequency();
}

std::vector<Result_term>* Word_analyzer::analyze(Text* d)
{
	if (d == nullptr){//check
		throw std::runtime_error("text needed.");
	}

	Text* doc = chop(d);

	std::map<std::string, unsigned int> table;

	Text::iterator iter = doc->begin();
	Text::iterator end = doc->end();
	for (; iter != end; ++iter){//each line
		//split
		std::vector<std::string>* words = nullptr;
		words = split(*iter);

		std::vector<std::string>::iterator words_iter = words->begin();
		std::vector<std::string>::iterator words_end = words->end();
		for (; words_iter != words_end; ++words_iter){//for each word;
			std::string t = *words_iter;

			if (!filter->count(t)){
				continue;
			}

			if (!sensitive){//case sensitive?
				downcase(t);
			}

			if (table.count(t)){//already in map?
				table[t]++;
			}
			else{
				table.insert(std::map<std::string, unsigned int>::value_type(t, 1));
			}
		}

		delete words;//dispose memory
	}

	delete doc;//dispose memory

	std::vector<Result_term>* res = nullptr;
	res = new std::vector < Result_term > ;

	std::map<std::string, unsigned int>::iterator m_iter = table.begin();
	std::map<std::string, unsigned int>::iterator m_end = table.end();
	for (; m_iter != m_end; ++m_iter){//each record in map
		res->push_back(Result_term(m_iter->first, m_iter->second));
	}
	//sort
	switch (order){
	case lexical:
		std::sort(res->begin(), res->end(), lex_cmp);
		break;
	case lexical_r:
		std::sort(res->begin(), res->end(), lex_r_cmp);
		break;
	case frequency:
		std::sort(res->begin(), res->end(), fre_cmp);
		break;
	case frequency_r:
		std::sort(res->begin(), res->end(), fre_r_cmp);
		break;
	}

	return res;
}