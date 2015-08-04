#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "document.h"

using namespace std;

void bind_file(ifstream& f)//associate a input file stream with file
{
	while (true){
		//input name
		string name = "";
		cout << "Please input a file name (for input document): ";
		cin >> name;
		if (cin.eof()){
			throw std::runtime_error("Unexpected input end.");
		}
		if (cin.bad() || cin.fail()){
			throw std::runtime_error("input stream is not well.");
		}
		//try to load data
		try{
			f.open(name.c_str());
			if (!f){//open fail
				throw std::runtime_error("Can't open file!");
			}
			break;
		}
		catch (std::runtime_error& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			std::cout << "Try again." << std::endl;
			continue;
		}
	}
}

int main()//just for test
try{
	ifstream fin;
	bind_file(fin);
	cin.ignore(1024, '\n');//eat the enter
	Document d;
	fin >> d;//read d;

    cout << d;//output

    cout << "char_count: " << char_count(d) << endl;
	cout << "word_count_def1: " << word_count_def1(d) << endl;
	cout << "word_count_def2: " << word_count_def2(d) << endl;

	string pattern;
	string newstr;
	cout << "Input a pattern: " << endl;
	getline(cin, pattern);
	cout << "Input a string to substitute pattern: " << endl;
    getline(cin, newstr);
	Document::iterator iter = text_sub(d.begin(), d.end(), pattern, newstr);
	if (iter == d.end()){
		cout << "No substitute" << endl;
	}
	else{
		cout << d;//output again
	}
	return 0;
} catch (runtime_error& e){
	cerr << "Error: " << e.what() << endl;
	return 1;
}
catch (...){
	cerr << "Unknown Error" << endl;
	return 2;
}