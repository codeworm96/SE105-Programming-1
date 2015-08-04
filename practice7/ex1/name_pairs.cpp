#include "name_pairs.h"
#include "util.h"
#include <vector>
#include <string>
#include <iostream>

void Name_pairs::read_names()
{
	//input number of names;
	std::cout << "please input the number of names (one int(>0) in a line)" << std::endl;
	int n = 0;
	while (true){
		n = input_int();
		if (n > 0){
			break;
		}
		std::cout << "Invalid number. Try again." << std::endl;
	}
	//clear data;
	name.clear();
	age.clear();
	//input names;
	std::cout << "Please input " << n << " names below (one per line)" << std::endl;
	std::string s = "";
	for (int i = 0; i < n; ++i){
		std::getline(std::cin, s);
		if (std::cin.bad()){
			throw std::runtime_error("bad stream");
		}
		if (std::cin.eof()){
			throw std::runtime_error("unexpected end of file");
		}
		name.push_back(s);
	}
}

void Name_pairs::read_ages()
{
	//check
	if (name.size() <= 0){
		throw std::runtime_error("unable to read ages");
	}
	std::cout << "Below you should input " << name.size() << " ages." << std::endl;
	//clear
	age.clear();
	//read ages
	for (size_t i = 0; i < name.size(); ++i){
		std::cout << "Input age for " << name[i] << " :" << std::endl;
		double tmp = 0;
		while (true){
			tmp = input_double();
			if (tmp > 0){
				break;
			}
			std::cout << "invalid age. Try again." << std::endl;
		}
		age.push_back(tmp);
	}
}

void Name_pairs::print() const //output
{
	std::cout << name.size() << " (name,age) pairs. " << std::endl;
	for (size_t i = 0; i < name.size(); ++i){
		std::cout << '(' << name[i] << ',' << age[i] << ')' << std::endl;
	}
}

void Name_pairs::swap(int i, int j)//swap pairs
{
	std::string ts;
	ts = name[i];
	name[i] = name[j];
	name[j] = ts;

	double td;
	td = age[i];
	age[i] = age[j];
	age[j] = td;
}

void Name_pairs::qsort(int l, int r)//quick sort
{
	if (l + 1 >= r){
		return;
	}
	int j = l;
	for (int i = l + 1; i < r; ++i){
		if (name[i] < name[l]){
			++j;
			swap(j, i);
		}
	}
	swap(l, j);
	qsort(l, j);
	qsort(j + 1, r);
}
