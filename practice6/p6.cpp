/*本道题目的题号是：1
*要求是：两个文件中包含已排序的、空白字符间隔的单词，编写程序 将它们合并，所产生的结果文件中单词仍然有序排列。
*/
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cctype>

void downcase(std::string& s)//string.downcase
{
	for (size_t i = 0; i < s.size(); ++i){
		s[i] = tolower(s[i]);
	}
}
int compare(std::string a, std::string b)//compare, case ignored
{
	//downcase two strings
	downcase(a);
	downcase(b);
	//<=>
	if (a < b){
		return -1;
	}
	else{
		if (a > b){
			return 1;
		}
		else{
			return 0;
		}
	}
}
void load_file(std::string name, std::vector<std::string>& list)//load vector from file
{
	std::ifstream fin(name.c_str());
	if (!fin){//open fail
		throw std::runtime_error("Can't open file!");
	}
	list.clear();//initialize vector
	std::string tmp = "";
	while (fin >> tmp){
		list.push_back(tmp);
	}
	if (!fin.eof()){//check fin status
		throw std::runtime_error("Something wrong when read file.");
	}
}
void input_from_file(std::vector<std::string>& list)//let user choose file
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
		catch (std::runtime_error& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			std::cout << "Try again." << std::endl;
			continue;
		}
		std::cout << "File loaded successfully" << std::endl;
		//check data
		bool sorted = true;
		for (size_t i = 1; i < list.size(); ++i){
			if (compare(list[i - 1], list[i]) > 0){
				sorted = false;
				break;
			}
		}
		if (!sorted){
			std::cerr << "File is not sorted!" << std::endl;
			std::cout << "Try another file." << std::endl;
			continue;
		}
		break;
	}
}
void merge(const std::vector<std::string>& a, const std::vector<std::string>& b, std::vector<std::string>& c)
{
	c.clear();
	//merging
	std::vector<std::string>::const_iterator iter_a = a.begin();
	std::vector<std::string>::const_iterator iter_b = b.begin();
	while ((iter_a != a.end()) && (iter_b != b.end())){
		if (compare(*iter_a, *iter_b) < 0){
			c.push_back(*iter_a);
			++iter_a;
		}
		else{
			c.push_back(*iter_b);
			++iter_b;
		}
	}
	//handle left data
	while (iter_a != a.end()){
		c.push_back(*iter_a);
		++iter_a;
	}
	while (iter_b != b.end()){
		c.push_back(*iter_b);
		++iter_b;
	}
}
void write_file(std::string name, const std::vector<std::string>& list)//write vector to file
{
	std::ofstream fout(name.c_str());
	if (!fout){//open fail
		throw std::runtime_error("Can't open file!");
	}
	for (size_t i = 0; i < list.size(); ++i){
		if (i > 0){
			fout << ' ';
		}
		fout << list[i];
	}
	fout << std::endl;
}
void write_to_file(const std::vector<std::string>& list)//let user choose file to output
{
	while (true){
		//input file name
		std::string name = "";
		std::cout << "Please input a file name(for output): ";
		std::cin >> name;
		if (std::cin.eof()){
			throw std::runtime_error("Unexpected input end.");
		}
		if (std::cin.bad() || std::cin.fail()){
			throw std::runtime_error("input stream is not well.");
		}
		//try to write
		try{
			write_file(name, list);
		}
		catch (std::runtime_error& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			std::cout << "Try again." << std::endl;
			continue;
		}
		std::cout << "Write successful!" << std::endl;
		break;
	}
}

int main()
try{
    //input
	std::vector<std::string> input1;
	input_from_file(input1);
	std::vector<std::string> input2;
	input_from_file(input2);
	//merge
	std::vector<std::string> output;
	merge(input1, input2, output);
	//output
	write_to_file(output);
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