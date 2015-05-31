// Lab 5A, Date & Employee Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: G++
//Fig. 10.13: Employee.cpp
//Employee class member-function definitions.
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

#include "Employee.h" //Employee class definition
#include "Date.h" //Date class definition

//constructor uses member initializer list to pass insitializer values to constructors of member objects
Employee::Employee(const string &first, const string &last, const Date &DateofBirth, const Date &dateofHire)
:
    firstName (first), //initialize firstName
    lastName (last), //initialize lastName
    birthDate (DateofBirth), //initialize birthDate
    hireDate (dateofHire) //initialize hireDate
{
    //output Employee object to show when constructor is called
    cout<< "Employee object constructor: " << firstName << ' ' << lastName << endl;
} // end Employee constructor
//print Employee object
void Employee::print() const
{
    cout << lastName << ", " << firstName << " Hired: ";
    hireDate.print();
    cout << " Birthday: ";
    birthDate.print();
    cout << endl;
} // end function print

//output Employee object to show when its destructor is called
Employee::~Employee()
{
    cout << "Employee object destructor: " << lastName << ", " << firstName << endl;
} // end ~Employee destructo
