#ifndef DATEANDTIME_H
#define DATEANDTIME_H

#include <iostream>
#include <string>

class DateAndTime {

  private:

    //Attributes
    int date, time;

  public:

    DateAndTime();
    ~DateAndTime();
    DateAndTime(int theInt, std::string code);
    DateAndTime(int theDate, int theTime);
    int getDate(); 
    bool setDate(int newDate); 
    int getTime();
    bool setTime(int newTime);

};

#endif
