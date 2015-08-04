#include "input.h"

void skip_a_line()
{
	if (std::cin)
		return;//good stream : nothing to do
	if (std::cin.bad()){
		throw std::runtime_error("input stream bad!");//unable to fix
	}
	//skipping
	std::cin.clear();
	std::cin.ignore(1024, '\n');

	if (std::cin.eof()){
		throw std::runtime_error("unexcepted file end.");//end of file
	}
}
