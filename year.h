#ifndef yearH
#define yearH

#include "linkedlist.h"

class Year
{
  LinkedList days;
  Day d;
  int count;
  
public:
  Year();
  int findDate(int month, int day) const;
  Year& operator+= (const Day &d);
  Year& operator-= (const Day &d);
  void read();
  void searchDate(int month, int day) const;
  void searchSubject(const char *s) const;
};  // class Year


#endif
