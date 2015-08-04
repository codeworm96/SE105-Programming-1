/*本道题目的题号是：4
*要求是：编写函数 vector<string> split(const string& s)，将 s 中以空白符分隔的子串存入向量，作为结果返回。	
编写函数 vector<string> split(const string& s, const	string&	 w)，
新的 split函数除了默认的空白符外，还将 w 中所包含的字符也当成空白符。	
*/

#include "split.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

void printv(const std::vector<std::string>& vs)//print a vector
{
	for (size_t i = 0; i < vs.size(); ++i){
		std::cout << vs[i] << std::endl;
	}
}

int main()
try{
	//input
	std::cout << "Input a string: ";
	std::string s;
	std::getline(std::cin, s);
	if (!std::cin){
		throw std::runtime_error("input fail");
	}
	std::string w;
	std::cout << "Input whitespace: ";
	std::getline(std::cin, w);
	if (!std::cin){
		throw std::runtime_error("input fail");
	}
	//output
	std::cout << "split:" << std::endl;
	printv(split(s));
	std::cout << "split (with w):" << std::endl;
	printv(split(s, w));
	return 0;
}
catch (std::runtime_error& e){
	std::cerr << "Error: " << e.what() << std::endl;
	return 1;
}
catch (...){
	std::cerr << "Unknown error!" << std::endl;
	return 2;
}