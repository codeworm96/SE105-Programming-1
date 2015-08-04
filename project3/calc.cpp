#include "calc.h"
#include "utility.h"
#include <stdexcept>
#include <string>

Calculator::operator bool()//expression  left?
{
	return !ts.empty();
}

double Calculator::eval()//require: string end with ';'
{
	double d = expression();
	//check
	Token t(number);
	ts >> t;
	if ((!ts)||(t.type != end_of_exp)){
		throw std::runtime_error("unexpected abort");
	}
	return d;
}

double Calculator::primary()
{
	Token t(number);
	ts >> t;
	if (!ts){
		throw std::runtime_error("unexpected end of expression");
	}
	double d = 0.0;
	switch (t.type){
	case '(':
	{
		d = expression();
		ts >> t;
		if (!ts){
			throw std::runtime_error("unexpected end of expression");
		}
		if (t.type != ')'){
			ts.putback(t);
			throw std::runtime_error("\')\' expected");
		}
		break;
	}
	case number:
		d = t.value;
		break;
	case '-':
		return -primary();
		break;
	case '+':
		return primary();
		break;
	default:
		ts.putback(t);
		throw std::runtime_error("primary expected");
	}
	ts >> t;
	if (!ts){
		throw std::runtime_error("unexpected end of expression");
	}
	if (t.type == '!'){
		int n = d;
		if (n != d){
			throw std::runtime_error("!:invalid argument");
		}
		return math::factorial(n);
	}
	else{
		ts.putback(t);
		return d;
	}
}

double Calculator::term()
{
	Token t(number);
	double res = primary();
	while (ts >> t){
		switch (t.type){
		case '*':
			res *= primary();
			break;
		case '/':
		{
			double right = primary();
			if (right == 0){
				throw std::runtime_error("/:division by zero");
			}
			res /= right;
			break;
		}
		case '%':
		{
			int left = res;
			double d = primary();
			int right = d;
			if ((left != res) || (right != d)){
				throw std::runtime_error("%:invalid operand");
			}
			if (right == 0){
				throw std::runtime_error("%:division by zero");
			}
			res = left % right;
			break;
		}
		default:
			ts.putback(t);
			return res;
		}
	}
	throw std::runtime_error("unexpected end of expression");
}

double Calculator::expression()
{
	Token t(number);
	double res = term();
	while (ts >> t){
		switch (t.type){
		case '+':
			res += term();
			break;
		case '-':
			res -= term();
			break;
		default:
			ts.putback(t);
			return res;
		}
	}
	throw std::runtime_error("unexpected end of expression");
}