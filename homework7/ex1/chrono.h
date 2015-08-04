/*本道题目的题号是：1
*要求是:编写并运行课程中的样例程序（9.8），并且分析该程序的结构与功能，以完成下列各项任务。
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
		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }

		//modifying operations:
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);

		Day day_of_week() const;//only support date after 1970/1/1
	private:
		int y;
		Month m;
		int d;
		void next_month();
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