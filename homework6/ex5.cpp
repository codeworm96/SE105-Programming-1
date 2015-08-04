/*本道题目的题号是：5
*要求是：编写程序，读取一个以空白符间隔的数值文件，按升序输出这些数值，每行一个值。
每个数值只输出一次，如果一个数值在原文件中出现多次，同时输出它出现的次数。
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

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
	//work
	std::sort(numbers.begin(), numbers.end());
	std::vector<int> num;
	std::vector<int> times;
	for (size_t i = 0; i < numbers.size(); ++i){
		if (i == 0 || numbers[i] != numbers[i - 1]){
			num.push_back(numbers[i]);
			times.push_back(1);
		}
		else{
			times[times.size() - 1]++;
		}
	}
	//output
	for (size_t i = 0; i < num.size(); ++i) {
		std::cout << num[i];
		if (times[i]>1){
			std::cout << '\t' << times[i];
		}
		std::cout << std::endl;
	}
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