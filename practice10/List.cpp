#include "List.h"

List::List() :head(0){}//init

void List::output(std::ostream& os) const
{
	List_node* cur = head;
	while (cur){//not end
		cur->data->output(os);
		cur = cur->next;
	}
}

List::~List()
{
	List_node* cur = head;
	while (cur){
		delete cur->data;
		List_node* p = cur;
		cur = cur->next;
		delete p;
	}
}

void List::insert(Person* p)
{
	if (head){//already have records
		List_node* cur = head;
		List_node* last = 0;
		while (cur){//find insert position
			if (*p <= *(cur->data))
				break;
			last = cur;
			cur = cur->next;
		}

		List_node* add = new List_node;
		add->data = p;
		add->next = cur;
		if (last){//first one?
			last->next = add;
		}
		else{
			head = add;
		}
	}
	else{//first one
		head = new List_node;
		head->data = p;
		head->next = 0;
	}
}