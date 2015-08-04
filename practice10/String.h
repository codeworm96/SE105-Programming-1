#ifndef STRING_H
#define STRING_H

#include <string.h>
#include <iostream>
using namespace std;

//Very simple String class

class String
{
public:
	//default constructor
	String(const char* s = 0){ set_str(s); }

	//copy constructor
	String(const String& rhs){ set_str(rhs.str); }

	//destructor
	~String(void){ delete[] str; }

	//access functions
	const char* c_str(void) const { return (const char*)str; }
	int length(void) const{ return strlen(str); }

	//assignment operators
	String& operator=(const char *rhs);
	String& operator=(const String& rhs);

	//equality test operator
	bool operator==(const String& rhs) const;

    //other comparers
	bool operator<(const String& rhs) const;
	bool operator<=(const String& rhs) const;

	//concatenation operator
	const String operator+(const String& rhs) const;

private:
	//auxillary help function for constructors
	void set_str(const char*);

	//pointer to string value
	char *str;
};

//input operator
istream& operator>>(istream& istr, String& s);

//output operator
ostream& operator<<(ostream& ostr, const String& s);

#endif