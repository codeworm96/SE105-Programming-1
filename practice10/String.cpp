#include <assert.h>
#include <iostream>
#include "String.h"

const int NAMLEN = 80;

String& String::operator=(const char *rhs)
{
	if (str != rhs){
		delete[] str;
		set_str(rhs);
	}
	return *this;
}

String& String::operator=(const String& rhs)
{
	if (this != &rhs){
		delete[] str;
		set_str(rhs.str);
	}
	return *this;
}

bool String::operator==(const String& rhs) const
{
	if (this == &rhs)//time saver
		return true;
	return (strcmp(str, rhs.str) == 0);
}

bool String::operator<(const String& rhs) const
{
	return (strcmp(str, rhs.str) < 0);
}
bool String::operator<=(const String& rhs) const
{
	return (strcmp(str, rhs.str) <= 0);
}

const String String::operator+(const String& rhs) const
{
	char* r = new char[length() + rhs.length() + 1];//temporary
	assert(r != 0);
	strcpy_s(r, length() + rhs.length() + 1, str);//init with lhs
	strcpy_s(r + length(), rhs.length() + 1, rhs.str);//add rhs
	String result(r);//construct String object
	delete[] r;
	return result;
}

void String::set_str(const char* s)
{
	if (s){
		str = new char[strlen(s) + 1];
		assert(str != 0);
		strcpy_s(str, strlen(s) + 1, s);
	}
	else{
		str = new char[1];
		assert(str != 0);
		str[0] = '\0';
	}
}

istream& operator>>(istream& istr, String& s)
{
	char buf[NAMLEN];
	buf[0] = '\0';
	if (istr >> buf){
		s = buf;
	}
	else{
		s = "";
	}
	return istr;
}

ostream& operator<<(ostream& ostr, const String& s)//output
{
	return ostr << s.c_str();
}