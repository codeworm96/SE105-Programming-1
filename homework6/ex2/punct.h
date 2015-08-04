#ifndef PUNCT_H
#define PUNCT_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Punct_stream
{
public:
	Punct_stream(istream& is) :source(is), sensitive(true){};//constructor
	void whitespace(const string& s)//make s the whitespace set
	{
		white = s;
	}
	void add_white(char c)//add to the whitespace set
	{
		white += c;
	}
	bool is_whitespace(char c);//is c in the whitespace set?

	void case_sensitive(bool b)//set sensitive
	{
		sensitive = b;
	}
	bool is_case_sensitive()
	{
		return sensitive;
	}

	Punct_stream& operator>>(string& s);//input
	operator bool();//convert to bool
private:
	istream& source;
	istringstream buffer;
	string white;
	bool sensitive;
};

#endif //PUNCT_H