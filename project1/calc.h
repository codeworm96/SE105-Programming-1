#ifndef CALC_H
#define CALC_H

#include <string>
#include "token.h"

class Calculator
{
public:
	double eval();//eval a expression
	void recover() {
		ts.ignore(';');
	};//recover from error;
	Calculator(std::string exp) :ts(exp){};//constructor
	operator bool();//expression  left?
private:
	Token_stream ts;
	double expression();
	double term();
	double primary();
};

#endif //CALC_H