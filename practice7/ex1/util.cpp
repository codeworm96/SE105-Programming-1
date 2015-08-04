#include <iostream>
#include <string>
#include "util.h"

double input_double()
{
	double res = 0;
	while (true){
		if (std::cin >> res){//ok
			//clear '\n'
			std::string s;
			std::getline(std::cin,s);
			return res;
		}
		if (std::cin.eof()){
			throw std::runtime_error("unexpected end of file");
		}
		if (std::cin.bad()){
			throw std::runtime_error("bad stream");
		}
		std::cout << "Invalid double. please try again" << std::endl;
		//recover
		std::cin.clear();
		std::cin.ignore(1024, '\n');
	}
}

int input_int()
{
	int res = 0;
	while (true){
		if (std::cin >> res){//ok
			//clear '\n'
			std::string s;
			std::getline(std::cin, s);
			return res;
		}
		if (std::cin.eof()){
			throw std::runtime_error("unexpected end of file");
		}
		if (std::cin.bad()){
			throw std::runtime_error("bad stream");
		}
		std::cout << "Invalid int. please try again" << std::endl;
		//recover
		std::cin.clear();
		std::cin.ignore(1024, '\n');
	}
}