
#include <iostream>
#include <iomanip>
#include "day.h"
#include "dayofweek.h"

using namespace std;

Day::Day():apptCount(0)
{
} // Day()


Day::Day(short mo, short d): day(d),month(mo), apptCount(0)
{
} // Day() custom constructor


Day::Day(const Day &d)
{
	day = d.day;
  month = d.month;
  apptCount = d.apptCount;

	for(int i = 0; i < apptCount; i++)
	{
		appts[i] = new Appointment();
		*appts[i] = *d.appts[i];
	}
  
} // Day() copy constructor
 

Day::~Day()
{
  for(int j = 0; j < apptCount; j++)
    delete  appts[j];
} // ~Day()


int Day::compareDate(short mo, short d) const
{
  if(month == mo)
    return day - d;
  else
    return month - mo;
}  // compareDate()


short Day::getDay() const
{
  return day;
} // getDay()


short Day::getMonth() const
{
  return month;
} // getMonth()



ostream& operator<< (ostream & os, const Day &d)
{
  DayOfWeek dayOfWeek(d.month, d.day);
  dayOfWeek.read();
  os << dayOfWeek;
  return os;
} // operator<<




Day& Day::operator= (const Day &d)
{
  if(this == &d)
    return *this;

  for(int j = 0; j < apptCount; j++)
    delete  appts[j];

  day = d.day;
  month = d.month;
  apptCount = d.apptCount;

  for(int i = 0; i < apptCount; i++)
  {
    appts[i] = new Appointment();
    *appts[i] = *d.appts[i];
  }  // for each appointment

  return *this;
}  // operator=


istream& operator>> (istream & is, Day &d)
{
  d.appts[0] = new Appointment();
  is >> *(d.appts[0]);
  d.apptCount = 1;
  return is;
}  // return operator>>()


Day& Day::operator+= (const Day &d)
{
  for(int i = 0; i < d.apptCount; i++)
  {
    appts[apptCount] = new Appointment();
    *appts[apptCount] = *(d.appts[i]);
    apptCount++;
  }  // for each apointment

  return *this;
} // operator+=()


bool Day::operator< (const Day &d)
{
  if(month == d.month)
    if(day - d.day >= 0)
      return false; 
    else
      return true;
  
  else
    if(month > d.month)
      return false;
   
  else // month < d.month
      return true;
} // operator<()


bool Day::operator== (const Day& d)
{
  if(day == d.day && month == d.month)
    return true;
  
  return false;
} // operator==()


void Day::printAppts() const
{
  for(int j = 0; j < apptCount; j++)
    cout << *appts[j];
} // printAppts()


void Day::printSubject(const char *s, bool &found) const
{
  for(int j = 0; j < apptCount; j++)
    if(*appts[j] == Appointment(s))
    {
      if(!found)
        cout << "Date                           Start End   Subject         "
          << "Location\n";

      cout << *this;
      cout << *appts[j];
      found = true;
    }  // if subject matches
} // printSubject()


void Day::read()
{
  appts[apptCount] = new Appointment;
  appts[apptCount++]->read();
} // read()

