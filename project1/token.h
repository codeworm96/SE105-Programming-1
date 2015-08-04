#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <deque>

const char end_of_exp = ';';
const char number = '0';

struct Token
{
	char type;
	double value;
	Token(char c) :type(c), value(0){};
	Token(double x) :type(number), value(x){};
};

class Token_stream
{
public:
	Token_stream(std::string s);//constructor
	Token_stream& operator>>(Token&);
	void putback(Token);
	operator bool();//convert to bool
	bool empty();//Token left?
	void ignore(char);//ignore chars before ch (ch included)
private:
	std::deque<Token> data;//buffer
	bool goodbit;
};

#endif //TOKEN_H