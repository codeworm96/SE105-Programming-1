#include "view.h"
#include <iostream>
#include <string>
#include <stdexcept>

const std::string prompt = ">";
const std::string result = "= ";

std::string View::input()//input a string
{
	std::cout << prompt;//prompt
	std::string res = "";
	getline(std::cin,res);//get a line
	if (!std::cin){//check
		throw std::runtime_error("input fail");
	}
	return res;
}

void View::output(double res)//output result
{
	std::cout << result << res << std::endl;
}

void View::error(std::string s)//show error message
{
	std::cerr << "Error: " << s << std::endl;
}