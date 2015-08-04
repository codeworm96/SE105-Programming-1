/*本道题目的题号是：1
*要求是：一个文件中保存着以空白符间隔的整数，请编写程序求此文件中所有整数之和。
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

void load_file(std::string name, std::vector<int>& list)//load vector from file
{
	std::ifstream fin(name.c_str());
	if (!fin){//open fail
		throw std::runtime_error("Can't open file!");
	}
	list.clear();//initialize vector
	std::string tmp = "";
	while (fin >> tmp){
		int t;
		size_t sz = 0;
		t = stoi(tmp, &sz, 0);
		if (sz < tmp.size()){//something left
			throw std::runtime_error("invaild input");
		}
		list.push_back(t);
	}
	if (!fin.eof()){//check fin status
		throw std::runtime_error("Something wrong when read file.");
	}
}
void input_from_file(std::vector<int>& list)//let user choose file
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
		//try to load data
		try{
			load_file(name, list);
		}
		catch (std::invalid_argument&)
		{
			std::cerr << "Error: invalid input" << std::endl;
			std::cout << "Try again." << std::endl;
			continue;
		}
		catch (std::out_of_range&)
		{
			std::cerr << "Error: out of range" << std::endl;
			std::cout << "Try again." << std::endl;
			continue;
		}
		catch (std::runtime_error& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			std::cout << "Try again." << std::endl;
			continue;
		}
		std::cout << "File loaded successfully" << std::endl;
		break;
	}
}

int main()
try{
	std::vector<int> numbers;
	input_from_file(numbers);//input

	int sum = 0;
	for (size_t i = 0; i < numbers.size(); ++i){
		sum += numbers[i];
	}

	std::cout << "Sum= " << sum << std::endl;//output
	return 0;
}
catch (std::runtime_error& e){
	std::cerr << "Error: " << e.what() << std::endl;
	return 1;
}
catch (...){
	std::cerr << "Unknown error! " << std::endl;
	return 2;
}