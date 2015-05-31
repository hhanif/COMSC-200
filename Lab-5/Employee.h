// Lab 5A, Date & Employee Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: G++
//Fig. 10.12: Employee.h
//Employee class definition showing composition.
//Member function defined in Employee.cpp.
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.h" //include Date class definition
using std::string;

class Employee
{
public:
    Employee( const string &, const string &, const Date &, const Date & );
    void print() const;
    ~Employee(); //provided to confirm destruction order
private:
    string firstName; //composition: member object
    string lastName; //composition: member object
    const Date birthDate; //composition: member object
    const Date hireDate; //composition: member object
}; // end class Employee

#endif
