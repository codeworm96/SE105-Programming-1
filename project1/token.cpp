#include "token.h"
#include <deque>
#include <sstream>
#include <stdexcept>

Token_stream::operator bool()//convert to bool
{
	return goodbit;
}

bool Token_stream::empty()//token left?
{
	return data.empty();
}

Token_stream& Token_stream::operator>> (Token& t)
{
	if (data.empty()){  //check
		goodbit = false;
		return *this;
	}
	t = data.front();
	data.pop_front();
	return *this;
}

void Token_stream::putback(Token t)
{
	data.push_front(t);
}

Token_stream::Token_stream(std::string s)//constructor
{
	std::stringstream ss(s);
	char ch;
	while (ss >> ch){
		if (((ch <= '9') && (ch >= '0')) || (ch == '.')){//double
			ss.unget();
			double x;
			ss >> x;
			data.push_back(Token(x));
		}
		else{//symbol
			data.push_back(Token(ch));
		}
	}
	if (!ss.eof()){//check
		throw std::runtime_error("can't create token stream.");
	}
	//optional ';'
	if ((data.size() == 0) || (data[data.size() - 1].type != end_of_exp)){
		data.push_back(Token(end_of_exp));
	}
	goodbit = true;
}

void Token_stream::ignore(char ch)//ignore chars before ch (ch included)
{
	while (!data.empty()){
		Token t = data.front();
		data.pop_front();
		if (t.type == ch){
			break;
		}
	}
}