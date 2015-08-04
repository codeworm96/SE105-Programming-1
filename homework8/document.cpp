#include "document.h"
#include <list>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <iterator>

Document::iterator& Document::iterator::operator++()
{
	++pos;
	while ((ln->begin() != ln->end()) && (pos == ln->end())){ //if it is the end of last line do nothing
		++ln;
		pos = ln->begin();
	}
	return *this;
}

std::istream& operator>>(std::istream& is, Document& d)//must be a '\n' before end of file
{
	char ch;
	while (is.get(ch)){
		d.line.back().push_back(ch);
		if (ch == '\n'){
			d.line.push_back(Line());
		}
	}
	if (d.line.back().begin() != d.line.back().end()){//check for the empty line at last
		throw std::runtime_error("format error!");
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, Document& d)
{
	Document::iterator iter = d.begin();
	Document::iterator e = d.end();
	for (; iter != e; ++iter){
		os << *iter;
	}
	return os;
}

unsigned int char_count(Document& d)
{
	unsigned int count = 0;
	Document::iterator iter = d.begin();
	Document::iterator e = d.end();
	for (; iter != e; ++iter){
		++count;
	}
	return count;
}

unsigned int word_count_def1(Document& d)
{
	bool in_word = false;//found a word?
	unsigned int count = 0;
	Document::iterator iter = d.begin();
	Document::iterator e = d.end();
	for (; iter != e; ++iter){
		if (isspace(*iter)){//is space characters
			if (in_word){//end of word
				++count;
				in_word = false;
			}
		}
		else{
			in_word = true;
		}
	}
	if (in_word){//deal the last word
		++count;
	}
	return count;
}

unsigned int word_count_def2(Document& d)
{
	bool in_word = false;//found word?
	unsigned int count = 0;
	Document::iterator iter = d.begin();
	Document::iterator e = d.end();
	for (; iter != e; ++iter){
		if (!isalnum(*iter)){
			if (in_word){//end of word
				++count;
				in_word = false;
			}
		}
		else{
			in_word = true;
		}
	}
	if (in_word){//handle the last word
		++count;
	}
	return count;
}

bool in_a_line(const std::string& s)//is s a multi-line string?
{
	for (std::string::size_type i = 0; i < s.size(); ++i){
		if (s[i] == '\n'){
			return false;
		}
	}
	return true;
}

//Does string that begins at first match s?
bool match(Document::iterator first, Document::iterator last, const std::string& s)
{
	std::string::size_type i = 0;
	Document::iterator iter = first;
	while ((iter != last) && (i != s.size())){
		if (*iter != s[i]){
			break;
		}
		++i;
		++iter;
	}
	return (i == s.size());
}

Document::iterator text_find(Document::iterator first, Document::iterator last, const std::string& s)
{
	if (s.size() == 0)
		return last;//can't find an empty string
	Document::iterator iter = first;
	for (; iter != last; ++iter){
		if (*iter == s[0]){//the first character is same
			if (match(iter, last, s)){//check left
				return iter;
			}
		}
	}
	return last;
}

Line::iterator line_sub(Line& ln, Line::iterator first, Line::iterator last, const std::string& s)
{
	Line::iterator iter = first;
	std::string::const_iterator si = s.begin();
	while (iter != last&&si != s.end()){
		*iter = *si;//common part, just copy
		++iter;
		++si;
	}
	if (iter != last){//pattern left, erase
		return ln.erase(iter, last);
	}
	if (si != s.end()){//newstring left , insert
		Line::iterator p = ln.insert(last, si, s.end());
		std::advance(p, s.end() - si);
		return p;
	}
	return last;//same length
}

Document::iterator text_sub(Document::iterator first, Document::iterator last, const std::string& pattern, const std::string& newstr)
{
	if (!in_a_line(pattern) || !in_a_line(newstr) || pattern.size() == 0){
		return last;//failed
	}
	Document::iterator iter = text_find(first, last, pattern);
	if (iter == last){//not found
		return iter;
	}
	std::list<Line>::iterator ln = iter.getLn();//Line
	//mark position in line
	Line::iterator pb = iter.getPos();
	Line::iterator pe = pb;
	std::advance(pe, pattern.size());
	//use substitute for line
	Line::iterator pos = line_sub(*ln, pb, pe, newstr);
	return Document::iterator(ln, pos);
}

