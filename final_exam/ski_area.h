#ifndef SKI_AREA_H
#define SKI_AREA_H

#include <string>
#include <vector>

class Ski_area
{
public:
	class Error{};

	const int MAX_HEIGHT = 500;
	const int MIN_HEIGHT = 0;

	Ski_area(const std::string& file_name);//load ski area form file
	int get_r() const { return r; } 
	int get_c() const { return c; }
	int get_height(int rr, int cc) const;//NOTE: r,c begin with 1!!!, returns MAX_HEIGHT + 1 when out of range
private:
	int r;
	int c;
	std::vector<std::vector<int> > data;
};

#endif //SKI_AREA_H