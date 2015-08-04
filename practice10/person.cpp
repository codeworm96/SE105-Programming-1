#include "person.h"
#include "date.h"
#include "String.h"

Person::Person(String n, String f, Date d) :name(n), first(f), birth(d){}

//getters
String Person::get_name() const
{
	return name;
}

String Person::get_first() const
{
	return first;
}

Date Person::get_birth() const
{
	return birth;
}

void Person::output(std::ostream& os) const
{
	os << name << ' ' << first << ' ';
	birth.output(os);
	os << std::endl;
}

bool Person::operator<=(const Person& other) const
{
	return ((name < other.name) || ((name == other.name) && (first <= other.first)));
}