// Lab 5A, Date & Employee Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: G++
//Fig. 10.10: Date.h
//Date class definition: Member functions defined in Date.cpp
#ifndef DATE_H
#define DATE_H

class Date{
public:
    static const int monthsPerYear = 12; //number of months in a year
    Date(int = 1, int = 1, int = 1900); //default constructor
    void print() const; //print date in month/day/year formar
    ~Date(); //provided to confirm destruction order
private:
    int month; //1-12
    int day; //1-31 based on month
    int year; //any year
    
    //utility function to check if day is proper for month and year
    int checkDay( int ) const;
}; //end class date

#endif
