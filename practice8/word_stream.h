#ifndef WORD_STREAM_H
#define WORD_STREAM_H

#include <iostream>
#include <sstream>
#include <stdexcept>

//position
class Pos
{
public:
	//constructor
	Pos(unsigned long l, unsigned long w) :line(l), word(w){ //line/word from 1
		if ((l == 0) || (w == 0)){
			throw std::runtime_error("invalid position.");
		}
	}
	//getters
	unsigned long get_line() const { return line; }
	unsigned long get_word() const { return word; }
private:
	unsigned long line;
	unsigned long word;
};

class Word
{
public:
	//constructor
	Word(const std::string& w, const Pos& p) :word(w), position(p){}
	//getters
	std::string get_word() const { return word; }
	Pos get_pos() const { return position; }
private:
	std::string word;
	Pos position;
};

bool operator<(const Word&, const Word&);//Word compare

class Word_stream
{
public:
	//constructor
	Word_stream(std::istream& is) :source(is),line(0),word(0){}
	//read
	Word_stream& operator>>(Word&);
	operator bool(){ return !(source.fail()||source.bad())&&source.good(); }
private:
	bool is_word(const std::string&);//word check
	std::istringstream buffer;
	std::istream& source;
	unsigned long line;
	unsigned long word;
};

#endif //WORD_STREAM_H