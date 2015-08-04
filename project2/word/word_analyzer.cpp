#include <list>
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <map>
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

std::vector<std::string>* Word_analyzer::split(std::string s)
{
	std::vector<std::string>* res = new std::vector < std::string > ;

	static std::string punct(" \t\v,.;:'\"!()?-`~[]{}\\|/<>");//punctuations

	std::string::size_type prev = 0;
	std::string::size_type pos = 0;
	while ((pos = s.find_first_of(punct,pos)) != std::string::npos)
	{
		std::string t = s.substr(prev, pos - prev);//slice

		if (t != ""){//check
			res->push_back(t);
		}
		//restore pos
		pos++;
		prev = pos;
	}
	//last word
	std::string t = s.substr(prev);
	if (t != ""){
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

std::vector<Result_term>* Word_analyzer::analyze(Text* doc)
{
	if (doc == nullptr){//check
		throw std::runtime_error("text needed.");
	}

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

			if (!sensitive){//case sensitive?
				downcase(t);
			}

			if (t.size() < 3){
				continue;
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