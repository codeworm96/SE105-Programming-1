#ifndef VIEW_H
#define VIEW_H

#include <string>

class View
{
public:
	std::string input();//input a string
	void output(double);//output result
	void error(std::string);//show error message
};

#endif //VIEW_H