#include "word_stream.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>

bool Word_stream::is_word(const std::string& s)//word check
{
	for (std::string::size_type i = 0; i < s.size(); ++i){
		if (!std::isalpha(s[i])){
			return false;
		}
	}
	return true;
}

Word_stream& Word_stream::operator>>(Word& ww)
{
	std::string s = "-";
	while (!is_word(s)){
		while (!(buffer >> s)){
			//check
			if (buffer.bad()){
				throw std::runtime_error("bad stringstream");
			}
			if (!source.good()){
				return *this;
			}
			//a new line
			buffer.clear();
			std::string buf;
			std::getline(source, buf);
			++line;
			word = 0;
			buffer.str(buf);
		}
		++word;
	}
	ww = Word(s, Pos(line, word));
	return *this;
}

bool operator<(const Word& a, const Word& b)
{
	return (a.get_word() < b.get_word());
}