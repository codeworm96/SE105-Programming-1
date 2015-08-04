#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include "split.h"

std::vector<std::string> split(const std::string& s)//use stringstream to split
{
	std::istringstream iss(s);
	std::string tmp = "";
	std::vector<std::string> res;
	while (iss >> tmp){
		res.push_back(tmp);
	}
	if (!iss.eof()){
		throw std::runtime_error("split error");
	}
	return res;
}

std::vector<std::string> split(const std::string& s, const std::string& w)
{
	//replace
	std::string line = s;
	for (size_t i = 0; i < line.size(); ++i){
		for (size_t j = 0; j < w.size(); ++j){
			if (w[j] == line[i]){
				line[i] = ' ';
				break;
			}
		}
	}
	return split(line);
}
