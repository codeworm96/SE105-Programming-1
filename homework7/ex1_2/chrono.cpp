#include "chrono.h"
#include <iostream>

namespace Chrono{
	Date::Date(int yy, Month mm, int dd)
	{
		pack(yy, mm, dd);
	}
	Date& default_date()
	{
		static Date dd(2001, Date::jan, 1);
		return dd;
	}
	Date::Date()
		:_days(default_date().days())
	{
	}
	void Date::add_day(int n)
	{
		if (n < 0){
			throw Invalid();//not support
		}
		_days += n;
	}

	void Date::next_month()//add a month
	{
		int y;
		Month m;
		int d;
		unpack(y, m, d);
		if (m == dec){
			y++;
			m = jan;
		}
		else{
			m = Month(m + 1);
		}
		pack(y, m, d);
	}

	void Date::add_month(int n)
	{
		if (n < 0){
			throw Invalid();//not support
		}
		int y;
		Month m;
		int d;
		unpack(y, m, d);
		for (int i = 0; i < n; ++i){
			if (m == dec){
				y++;
				m = jan;
			}
			else{
				m = Month(m + 1);
			}
		}
		while (d>days_in_month(y, m)){
			d -= days_in_month(y, m);
			if (m == dec){
				y++;
				m = jan;
			}
			else{
				m = Month(m + 1);
			}
		}
		pack(y, m, d);
	}

	void Date::add_year(int n)
	{
		if (n < 0){
			throw Invalid();//not support
		}
		int y;
		Month m;
		int d;
		unpack(y, m, d);

		if (m == feb&&d == 29 && !leapyear(y + n)){//beware of leap years!
			m = mar;
			d = 1;
		}
		y += n;

		pack(y, m, d);
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
		if (y < 1970){
			return false;//not support
		}
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
		return a.days()==b.days();
	}
	bool operator!=(const Date& a, const Date& b)
	{
		return !(a == b);
	}

	Date::Day Date::day_of_week() const
	{
		int res = 4;//1970/1/1 is thursday
		res += _days;
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

	void Date::unpack(int& y, Month& m, int& d) const //to normal format
	{
		int yy = 1970;
		int mm = 1;
		int left = _days + 1;
		while (left>(leapyear(yy) ? 366 : 365)){
			left -= (leapyear(yy) ? 366 : 365);
			yy++;
		}
		while (left > days_in_month(yy, Month(mm))){
			left -= days_in_month(yy, Month(mm));
			mm++;
		}
		y = yy;
		m = Month(mm);
		d = left;
	}

	void Date::pack(int y, Month& m, int d)//to new format
	{
		if (!is_date(y,m,d)){
			throw Invalid();//not support
		}
		int res = 0;//from 1970/1/1
		for (int i = 1970; i < y; ++i){
			if (leapyear(i)){
				res += 366;
			}
			else{
				res += 365;
			}
		}
		for (int i = 1; i < m; ++i){
			res += days_in_month(y, Month(i));
		}
		res += (d - 1);
		_days = res;
	}
	//for compatibility , I strat to miss Ruby's virtual attribute
	int Date::day() const
	{
		int y;
		Month m;
		int d;
		unpack(y, m, d);
		return d;
	}
	Date::Month Date::month() const
	{
		int y;
		Month m;
		int d;
		unpack(y, m, d);
		return m;
	}
	int Date::year() const
	{
		int y;
		Month m;
		int d;
		unpack(y, m, d);
		return y;
	}
}