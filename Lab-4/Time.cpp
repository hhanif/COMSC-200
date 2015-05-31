// Lab 4A, Time Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: G++

#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
using std::setfill;
using std::setw;


#include "Time.h" // Include definition of class time

// Constructor function to initialize private data;
// Calls member function setTime to set variables;
// Default values are 0 (see class definition)
Time::Time(int hour, int minute, int second)
{
    setTime(hour, minute, second);
} // End Time constructor

// Set hour, minute, and second values
void Time::setTime(int hour, int minute, int second)
{
    setHour(hour);
    setMinute(minute);
    setSecond(second);
} // end function setTime

// Set hour value
void Time::setHour( int h)
{
    hour = ( h >= 0 && h < 24) ? h : 0; // Validate hour
} // end function setHour

//set minute value
void Time::setMinute( int m)
{
    minute = ( m >= 0 && m < 60) ? m : 0; // Validate minute

} // end function setMinute

//set second value
void Time::setSecond( int s)
{
    second = ( s >= 0 && s < 60) ? s : 0; // Validate second
    
} // end function setSecond

// return hour value
int Time::getHour() const // get functions should be const
{
    return hour;
} // end function getHour

//return Minute Value
int Time::getMinute() const // get functions should be const
{
    return minute;
} // end function getMinute

int Time::getSecond() const // get functions should be const
{
    return second;
} // end function getSecond

//Print Time in universal-time format (HH:MM:SS)
void Time::printUniversal() const
{
    cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
} // end function
//Print Time in standard-time format (HH:MM:SS AM OR PM)
void Time::printStandard() const
{
    cout << ((hour==0 || hour == 12) ? 12 : hour %12) << ":" << setfill('0') << setw(2) << minute << ":" << setw(2) << second << (hour < 12 ? "AM" : "PM");
} //end function
