#include <iostream>
#include "chrono.h"

using namespace Chrono;

int main()
try{
	Date d;
	Date dd;
	//basic test
	std::cout << "Default date" << std::endl;
	std::cout << d << std::endl;
	std::cout << "Input date as (2014,11,11):" << std::endl;
	std::cin >> d;
	std::cout << "Inputed date:" << std::endl;
	std::cout << d << std::endl;
	//test ==
	std::cout << "d==Default date?" << std::endl;
	std::cout << (d == dd) << std::endl;
	//test add
	int n;
	std::cout << "Add n days:" << std::endl;
	std::cin >> n;
	d.add_day(n);
	std::cout << d << std::endl;
	std::cout << "Add n months:" << std::endl;
	std::cin >> n;
	d.add_month(n);
	std::cout << d << std::endl;
	std::cout << "Add n years:" << std::endl;
	std::cin >> n;
	d.add_year(n);
	std::cout << d << std::endl;
	//test day of week
	std::cout << "Day of week: " << d.day_of_week() << std::endl;
	std::cout << "Next work day:" << next_workday(d) << std::endl;
	std::cout << "Week " << week_of_year(d) << std::endl;
	return 0;
}
catch (Date::Invalid){
	std::cerr << "invalid date" << std::endl;
}