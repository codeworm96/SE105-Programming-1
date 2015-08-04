#ifndef LIST_H
#define LIST_H

#include "person.h"
#include <iostream>

struct List_node //List in legacy code
{
	Person* data;
	List_node* next;
};

class List//wrapping class
{
public:
	List();//constructor
	~List();//destructor delete list
	void insert(Person* p);//at right place
	void output(std::ostream& os) const;//print out list
private:
	List_node* head;
};

#endif //LIST_H