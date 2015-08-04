/*本道题目的题号是：1 2 3
*要求是:
为Document编写一个查找并替换操作。
编写一个可以统计Document中字符总数的函数。
编写一个可以统计Document中字数的函数。该程序有两个版本：
一种把“字”定义为“以空格分隔的字符序列”，另
一种把“字”定义为“一个连续的数字或字母序列”。
*/
#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <list>
#include <vector>
#include <iostream>

typedef std::vector<char> Line;

struct Document
{
	class iterator  //iterator for Document
	{
	public:
		//start the iterator at line ll's character position pp:
		iterator(std::list<Line>::iterator ll,Line::iterator pp)
			:ln(ll), pos(pp){}
		//getters
		std::list<Line>::iterator getLn(){ return ln; }
		Line::iterator getPos() { return pos; }

		//dereference
		char& operator*(){ return *pos; }
		//compare
		bool operator==(const iterator& other) const
		{
			return ln == other.ln&&pos == other.pos;
		}
		bool operator!=(const iterator& other) const
		{
			return !(*this == other);
		}
		//move to next
		iterator& operator++();
	private:
		std::list<Line>::iterator ln;
		Line::iterator pos;
	};

	std::list<Line> line; //a document is a list of lines

	Document() { line.push_back(Line()); }//a document must end with an empty line
	iterator begin()
	{
		return iterator(line.begin(), line.begin()->begin());
	}
	iterator end()
	{
		std::list<Line>::iterator last = line.end();
		--last;//goto last line
		return iterator(last, last->end());
	}
};

std::istream& operator>>(std::istream& is, Document& d);//input, must be a '\n' before end of file
std::ostream& operator<<(std::ostream& os, Document& d);//output

unsigned int char_count(Document& d);//Task 2
//Task 3
unsigned int word_count_def1(Document& d);
unsigned int word_count_def2(Document& d);
//Task 1
//returns the position of the first character of matching string, or last for not found
Document::iterator text_find(Document::iterator first, Document::iterator last, const std::string& s);
//returns the position after the last character substituted,last for no substitute happened
Document::iterator text_sub(Document::iterator first, Document::iterator last, const std::string& pattern, const std::string& newstr);

#endif //DOCUMENT_H