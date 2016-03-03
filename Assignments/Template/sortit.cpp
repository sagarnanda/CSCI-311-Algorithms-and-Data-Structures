/* Any modifications to this file
 * will be overwritten with a copy
 * of the original file.
 * Version: 1.0
 */

#include<iostream>
#include<iomanip>
#include "Sorter.h"
class Time {
  private:
    int hour;
    int minute;
  public:
    Time() : hour(0), minute(0){}
    Time(int h, int m) : hour(h), minute(m){}
    Time(const Time& tm) : hour(tm.hour), minute(tm.minute){}
    bool operator<(const Time& rhs) const
    {
      return hour*60+minute < rhs.hour*60+minute;
    }
    friend std::istream& operator>>(std::istream& is, Time& tm)
    {
      is >> tm.hour; is.ignore(1); return is >> tm.minute;
    }
    friend std::ostream& operator<<(std::ostream& os, Time& tm)
    {
      os.fill('0'); 
      os << std::setw(2) << tm.hour << ':' << std::setw(2) << tm.minute;
      os.fill(' '); 
      return os;
    }
};

int main()
{
  int count;
  std::cin >> count;
  Sorter<short> sordid(count);
  short num;
  for(int i=0; i<count; ++i)
  {
    std::cin >> num;
    sordid.add(num);
  }
  std::cout << "WORKING WITH SHORT" << std::endl;
  std::cout << "===================" << std::endl;
  sordid.display();
  sordid.sort();
  sordid.display();

  std::cin >> count;
  Sorter<Time> timers(count);
  Time tm;
  for(int i=0; i<count; ++i)
  {
    std::cin >> tm;
    timers.add(tm);
  }
  std::cout << std::endl;
  std::cout << "WORKING WITH TIME" << std::endl;
  std::cout << "==================" << std::endl;
  timers.display();
  timers.sort();
  timers.display();

  return 0;
}
