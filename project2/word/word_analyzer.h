#ifndef WORD_ANALYZER_H
#define WORD_ANALYZER_H

#include <list>
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

typedef std::list<std::string> Text;  //text is a collection of strings
Text* load_from(std::istream& is);

//result term
class Result_term
{
public:
	Result_term(std::string w, unsigned int f) :word(w), frequency(f)
	{
		if (frequency <= 0){//check
			throw std::runtime_error("invalid result");
		}
	}
	//getters
	std::string get_word() const { return word; }
	unsigned int get_frequency() const { return frequency; }
private:
	std::string word;
	unsigned int frequency;
};

class Word_analyzer
{
public:
	enum Order { lexical, lexical_r, frequency, frequency_r };//order of output
	//constructor
	Word_analyzer(bool case_sensitive, Order order_by) :sensitive(case_sensitive), order(order_by){}

	std::vector<Result_term>* analyze(Text* doc);
private:
	bool sensitive;
	Order order;
	//supporting functions
	std::vector<std::string>* split(std::string s);//split a line
	void downcase(std::string& s);
};

#endif //WORD_ANALYZER_H