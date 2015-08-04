#include "date.h"
#include <iostream>

//constructors
Date::Date()
	:year(default_date().get_year())
	,month(default_date().get_month())
	,day(default_date().get_day()){}

Date::Date(int y, int m, int d) :year(y), month(m), day(d)
{
	if (!is_date(y, m, d)) throw Invalid();//check
}

//getters
int Date::get_day() const
{
	return day;
}

int Date::get_month() const
{
	return month;
}

int Date::get_year() const
{
	return year;
}

int Date::days_in_month(int y, int m)
{
	int res = 31;
	switch (m){
	case 2:
		res = (leapyear(y)) ? 29 : 28;
		break;
	case 4: case 6: case 9: case 11:
		res = 30;
		break;
	}
	return res;
}

bool Date::leapyear(int y)
{
	return (((y % 4 == 0) && (y % 100)) || (y % 400 == 0));
}

bool Date::is_date(int y, int m, int d)
{
	//assume that y is valid
	//check m
	if (m > 12 || m < 1){
		return false;
	}

	if (d <= 0) return false; //d must be positive

	if (days_in_month(y, m) < d){
		return false;
	}
	return true;
}

Date& Date::default_date()
{
	static Date dd(1970, 1, 1);
	return dd;
}

void Date::output(std::ostream& os) const
{
	os << get_year() << '.' << get_month() << '.' << get_day();
}

bool Date::input(std::istream& is)
{
	int y, m, d;
	char ch1, ch2;
	is >> y >> ch1 >> m >> ch2 >> d;
	if (!is) return false;
	if (ch1 != '.' || ch2 != '.'){//oops:format error
		return false;
	}
	if (!is_date(y, m, d)) throw Invalid();//check
	year = y;
	month = m;
	day = d;
	return true;
}