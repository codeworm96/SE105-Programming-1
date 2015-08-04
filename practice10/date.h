#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
public:
	class Invalid{};//invalid date
	//constructors
	Date();//default 1970.1.1
	Date(int y, int m, int d);
	//getters
	int get_day() const;
	int get_month() const;
	int get_year() const;
	//I/O
	bool input(std::istream& is);
	void output(std::ostream& os) const;
private:
	int day;
	int month;
	int year;
	//auxillary help function
	bool is_date(int y, int m, int d);
	bool leapyear(int y);
	int Date::days_in_month(int y, int m);
	Date& default_date();
};

#endif //DATE_H