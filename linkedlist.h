#ifndef linkedlistH
#define linkedlistH

#include "day.h"

class ListNode
{
private:
	Day day;
	ListNode *next;
	ListNode(const Day &d, ListNode *n);
	friend class LinkedList;
	
}; // class ListNode


class LinkedList
{
private:
	ListNode *head;

public:
	LinkedList();
	~LinkedList();
	const Day& operator[](int index) const;
	Day& operator[](int index);
	LinkedList& operator+=(const Day &d);
	LinkedList& operator-=(const Day &d);

}; // class LinkedList


#endif
