/*

Simple calculator for project1

Revision history:
    bugfix: -primary! cannot calculate (Zhang Yuning;yuning_zhang@sjtu.edu.cn) 2014/11/17
	error recover (Zhang Yuning;yuning_zhang@sjtu.edu.cn) 2014/11/14
	add ! (Zhang Yuning;yuning_zhang@sjtu.edu.cn) 2014/11/12
	add negative, % (Zhang Yuning;yuning_zhang@sjtu.edu.cn) 2014/11/12
	first commit (Zhang Yuning;yuning_zhang@sjtu.edu.cn) 2014/11/7

This program implements a basic expression calculator.
Input from cin; output to cout.

The grammar for input is:

Quit if input matches /^exit$/

Expression:
	Term
	Expression + Term
	Expression - Term
Term:
	Primary
	Term * Primary
	Term / Primary
	Term % Primary
Primary
	Number
	(Expression)
	Number!
	(Expression)!
	- Primary
	+ Primary

There can be more than one expression in one line, seperated by ;.The ; at the end of line can be leave out.
not support for !! or more !
*/
#include "view.h"
#include "calc.h"
#include <string>
#include <stdexcept>
#include <iostream>

const std::string exit_cmd = "exit";

void calculate()//Read-Eval-Print-Loop
{
    View view;
	while (true){
		//input
		std::string exp = view.input();
		//handle
		if (exp == exit_cmd){
			break;
		}
		Calculator calc(exp);
		while (calc){
			double res;
			try{
				res = calc.eval();
			}
			catch (std::runtime_error& e){
				view.error(e.what());
				calc.recover();
				continue;
			}
			//output
			view.output(res);
		}
	}
}

int main()
try{
	calculate();//independent calculate function
	return 0;
}
catch (std::runtime_error& e){
	std::cerr << "Serious error: " << e.what() << std::endl;
	return 1;
}
catch (...){
	std::cerr << "Unkonwn error!" << std::endl;
	return 2;
}