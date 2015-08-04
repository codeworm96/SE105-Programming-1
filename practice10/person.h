#ifndef PERSON_H
#define PERSON_H

#include "date.h"
#include "String.h"
#include <iostream>

class Person
{
public:
	//constructor
	Person(String n, String f, Date d);
	//getters
	String get_name() const;
	String get_first() const;
	Date get_birth() const;
	//output
	void output(std::ostream& os) const;
	//comparer
	bool operator<=(const Person& other) const;
private:
	String name;
	String first;
	Date birth;
};

#endif //PERSON_H