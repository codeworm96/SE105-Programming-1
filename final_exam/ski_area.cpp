#include <string>
#include <vector>
#include <fstream>
#include "ski_area.h"

Ski_area::Ski_area(const std::string& file_name)//load ski area form file
{
	std::ifstream ifs(file_name);
	if (!ifs){
		throw Error();
	}
	ifs >> r >> c;
	data.resize(r);
	for (int i = 0; i < r; ++i){
		data[i].resize(c);
		for (int j = 0; j < c; ++j){
			ifs >> data[i][j];
		}
	}
	if (!ifs){
		throw Error();
	}
}

int Ski_area::get_height(int rr, int cc) const //NOTE: r,c begin with 1!!!, returns MAX_HEIGHT + 1 when out of range
{
	if (rr > r || cc > c || rr < 1 || cc < 1){
		return MAX_HEIGHT + 1;
	}
	return data[rr - 1][cc - 1];
}