/*本道题目的题号是：1
*要求是:改变Date类的描述，用1970年1月1日（第0天）至今的天数表示日期，用一个long型成员保存此天数
重新实现9.8节中的函数。保证拒绝用这种方法无法表示的日期（第0天之前的日期也拒绝，即不允许负数天数）。
*/
#ifndef CHRONO_H
#define CHRONO_H

#include <iostream>

namespace Chrono{

	class Date{
	public:
		enum Day{
			sunday,monday,tuesday,wednesday,thursday,friday,saturday
		};

		enum Month{
			jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
		};

		class Invalid{}; //to throw as exception

		Date(int y, Month m, int d);//check for valid date and initalize
		Date();                     //default constructor
		//the default copy operations are fine

		//nomodifying operations:
		int day() const;
		Month month() const;
		int year() const;
		long days() const { return _days; }

		//modifying operations:
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);

		Day day_of_week() const;
	private:
		long _days;
		void next_month();
		void unpack(int& y, Month& m, int& d) const;
		void pack(int y, Month& m, int d);
	};

	int days_in_month(int y, Date::Month m);//days in month

	bool is_date(int y, Date::Month m, int d);//true for valid date

	bool leapyear(int y);  //true if y is a leap year

	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);

	std::ostream& operator<<(std::ostream& os, const Date& d);

	std::istream& operator>>(std::istream& is, Date& dd);

	Date next_workday(const Date& dd);
	int week_of_year(const Date& dd);

}//Chrono
#endif //CHRONO_H