#include "DateAndTime.h"

using namespace std;

/*
 * Default Constructor
 */
DateAndTime::DateAndTime() {
    date = 0;
    time = 0;
}

/** 
 * Overlaods the constructor but uses a string to determine if it will set time or date  
 * @param theInt value to set the variable to
 * @param code is a string that is used to determine which value is set
 */
DateAndTime::DateAndTime(int theInt, string code) {

    if (code == "date") {
        date = theInt;
        time = 0;
    }

    else if (code == "time" ) {
        time = theInt;
        date = 0; 
    }
}

/** 
 * A destructor for DateAndTime
 */
//~DateAndTime::DateAndTime(){}

/** 
 * Overloaded constructor to set both date and time
 * @param theDate sets the date
 * @param theTime sets the time
 */
DateAndTime::DateAndTime(int theDate, int theTime) {
    date = theDate;
    time = theTime;
}

/** 
 * Gets the date
 * @return date
 */
int DateAndTime::getDate() {
    return date;
}

/** 
 * Sets the date
 * @param newDate int value that is used to set the date
 * @return returns bool true once date is set
 */
bool DateAndTime::setDate(int newDate) {
    date = newDate;
    return true;
}

/** 
 * Gets the time. Time is used to set the time of activities
 * @return returns the time value
 */
int DateAndTime::getTime() {
    return time;
}

/** 
 * Sets the time. Time is used to set the time of activities
 * @param newTime int value used to set time without
 * @return returns bool true once time is set
 */
bool DateAndTime::setTime(int newTime) {
    time = newTime;
    return true;
}
