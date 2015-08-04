#include "chrono.h"
#include <iostream>

namespace Chrono{
	Date::Date(int yy, Month mm, int dd)
		:y(yy), m(mm), d(dd)
	{
		if (!is_date(yy, mm, dd)) throw Invalid();//check
	}
	Date& default_date()
	{
		static Date dd(2001, Date::jan, 1);
		return dd;
	}
	Date::Date()
		:y(default_date().year()),
		m(default_date().month()),
		d(default_date().day())
	{
	}
	void Date::add_day(int n)
	{
		if (n < 0){
			throw Invalid();//not support
		}
		d += n;
		while (d>days_in_month(y, m)){
			d -= days_in_month(y, m);
			next_month();
		}
	}

	void Date::next_month()//add a month
	{
		if (m == dec){
			y++;
			m = jan;
		}
		else{
			m = Month(m + 1);
		}
	}

	void Date::add_month(int n)
	{
		if (n < 0){
			throw Invalid();//not support
		}
		for (int i = 0; i < n; ++i){
			next_month();
		}
		while (d>days_in_month(y, m)){
			d -= days_in_month(y, m);
			next_month();
		}
	}

	void Date::add_year(int n)
	{
		if (n < 0){
			throw Invalid();//not support
		}
		if (m == feb&&d == 29 && !leapyear(y + n)){//beware of leap years!
			m = mar;
			d = 1;
		}
		y += n;
	}

	int days_in_month(int y, Date::Month m)
	{
		int res = 31;
		switch (m){
		case Date::feb:
			res = (leapyear(y)) ? 29 : 28;
			break;
		case Date::apr: case Date::jun: case Date::sep: case Date::nov :
			res = 30;
			break;
		}
		return res;
	}

	bool leapyear(int y)
	{
		return (((y % 4 == 0) && (y % 100)) || (y % 400 == 0));
	}
	bool is_date(int y, Date::Month m, int d)
	{
		//assume that y is valid
		if (d <= 0) return false; //d must be positive

		if (days_in_month(y, m) < d){
			return false;
		}
		return true;
	}

	Date::Month int_to_month(int x)
	{
		if (x <= 12 && x >= 1){
			return Date::Month(x);
		}
		else{
			throw Date::Invalid();
		}
	}

	std::ostream& operator<<(std::ostream& os, const Date& d)
	{
		return os << '(' << d.year()
			<< ',' << d.month()
			<< ',' << d.day() << ')';
	}

	std::istream& operator>>(std::istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')'){//oops:format error
			is.clear(std::ios_base::failbit);//set the fail bit
			return is;
		}
		dd = Date(y, int_to_month(m), d);//set dd;
		return is;
	}

	bool operator==(const Date& a, const Date& b)
	{
		return a.year() == b.year()
			&& a.month() == b.month()
			&& a.day() == b.day();
	}
	bool operator!=(const Date& a, const Date& b)
	{
		return !(a == b);
	}

	Date::Day Date::day_of_week() const
	{
		if (y < 1970){
			throw Invalid();//not support
		}

		int res = 4;//1970/1/1 is thursday
		for (int i = 1970; i < y; ++i){
			if (leapyear(i)){
				res += 366;
				res %= 7;
			}
			else{
				res += 365;
				res %= 7;
			}
		}
		for (int i = 1; i < m; ++i){
			res += days_in_month(y,Month(i));
			res %= 7;
		}
		res += (d - 1);
		res %= 7;
		return Day(res);
	}

	Date next_workday(const Date& dd)
	{
		Date d = dd;
		if (d.day_of_week() == Date::friday){//add 3
			d.add_day(2);
		}
		if (d.day_of_week() == Date::saturday){//add 2
			d.add_day(1);
		}
		d.add_day(1);
		return d;
	}
	int week_of_year(const Date& dd)
	{
		//accumulate days
		int sum = Date(dd.year(), Date::jan, 1).day_of_week();
		for (int i = 1; i < dd.month(); ++i){
			sum += days_in_month(dd.year(), Date::Month(i));
		}
		sum += (dd.day() - 1);

		return (sum / 7 + 1);
	}
}