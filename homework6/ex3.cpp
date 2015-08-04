/*本道题目的题号是：3
*要求是：编写程序，读取一个文本文件，将其中的字母都转换为小写，生成一个新文件。
*/

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

std::ifstream open_input()
{
	while (true){
		//input name
		std::string name = "";
		std::cout << "Please input a file name (for input): ";
		std::cin >> name;
		if (std::cin.eof()){
			throw std::runtime_error("Unexpected input end.");
		}
		if (std::cin.bad() || std::cin.fail()){
			throw std::runtime_error("input stream is not well.");
		}
		std::ifstream fin(name.c_str());
		if (!fin){//open fail
			std::cerr << "Can't open." << std::endl;
		}
		else{
			return fin;
		}
	}
}

std::ofstream open_output()
{
	while (true){
		//input name
		std::string name = "";
		std::cout << "Please input a file name (for output): ";
		std::cin >> name;
		if (std::cin.eof()){
			throw std::runtime_error("Unexpected input end.");
		}
		if (std::cin.bad() || std::cin.fail()){
			throw std::runtime_error("input stream is not well.");
		}
		std::ofstream fout(name.c_str());
		if (!fout){//open fail
			std::cerr << "Can't open." << std::endl;
		}
		else{
			return fout;
		}
	}
}

int main()
try{
	std::ifstream fin = open_input();//open input file
	std::ofstream fout = open_output();//open output file
	//to lower
	char c;
	while (fin.get(c)){
		fout << char(tolower(c));
	}
	if (!fin.eof()){
		std::cerr << "Error: convert not completed." << std::endl;
		return 1;
	}
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