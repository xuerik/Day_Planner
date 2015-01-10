#include "linkedlist.h"

ListNode::ListNode(const Day &d, ListNode *n)
{
  day = d;
  next = n;
} // ListNode()


LinkedList::LinkedList() : head(NULL)
{
} // LinkedList()


LinkedList::~LinkedList()
{
  ListNode *temp1 = head;
  ListNode *temp2;
  
  while(temp1)
  {
    temp2 = temp1->next;
    delete temp1;
    temp1 = temp2;
  }
} // ~LinkedList()


const Day& LinkedList::operator[](const int index) const
{
  ListNode *temp = head->next;
  
  if(index == 0 && head)
    return head->day;
  
  else
  {
    for(int i = 1; i < index; i++)
    {
      if(temp)
        temp = temp->next;
    }
    
    return temp->day;
  }
} // LinkedList operator[]


Day& LinkedList::operator[](const int index)
{
  ListNode *temp = head->next;
  
  if(index == 0 && head)
    return head->day;
  
  else
  {
    for(int i = 1; i < index; i++)
    {
      if(temp)
        temp = temp->next;
    }
    
    return temp->day;
  }
} // LinkedList operator[]


LinkedList& LinkedList::operator+=(const Day &d)
{
  ListNode *nodePtr = head;
  ListNode *left = head, *right;  
  
  while(nodePtr)
  {
    if(nodePtr->day < d)
    {
      left = nodePtr;
      nodePtr = nodePtr->next;
    }
    
    else
      break;
  }
  
  if(left)
  {
    right = nodePtr;

    if(left == right)
    {
      nodePtr = new ListNode(d, left);
      head = nodePtr;
      return *this;
    }

    nodePtr = new ListNode(d, right);
    left->next = nodePtr;
  }
  
  else // no head
  {
    head = new ListNode(d, NULL);
  }

  return *this;
} // LinkedList::operator+=


LinkedList& LinkedList::operator-=(const Day &d)
{
  ListNode *nodePtr = head->next;
  ListNode *left = head, *right;
  
  if(head->day == d)
  {
    right = head->next;
    delete head;
    head = right;
    
    return *this;
  }
  
  while(nodePtr)
  {

    if(nodePtr->day == d)
    {
        right = nodePtr->next;
        delete nodePtr;
        left->next = right;
        
        return *this;
    }

    left = nodePtr;
    nodePtr = nodePtr->next;
  }
  
  return *this;
} // LinkedList::operator-=
