// Lab 3A, Sales Person Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: G++
// Fig. 9.8: SalesPerson.cpp
// SalesPerson class member-function definitions.

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios;
using std::fixed;

#include <iomanip>
using std::setprecision;

#include <string>
using std::string;
using std::getline;

#include "SalesPerson.h" // Include SalesPerson class definition

// Initialize elements of arrays sales to 0.0
SalesPerson::SalesPerson()
{
    for ( int i = 0; i < monthsPerYear; i++ )
        sales[ i ] = 0.0;
} // end SalesPerson constructor

// get 12 sales figures from the user at the keyboard
void SalesPerson::getSalesFromUser()
{
    double salesFigure;
    char buf[100];

    
    for ( int i = 1; i <= monthsPerYear; i++ )
    {
        cout << "Enter sales amount for month " << i << ": ";
        cin >> buf;
        salesFigure = atof(buf);
        cin.ignore(1000, 10);
        setSales( i, salesFigure );
    } // end for
} // end function getSalesFromUser

// set one of the 12 monthly sales figures; function subtracts
// one from month value for proper subscript in sales array
void SalesPerson::setSales( int month, double amount )
{
    // test for valid month and amount values
    if ( month >= 1 && month <= monthsPerYear && amount > 0 )
        sales[ month - 1 ] = amount; // adjust for subscripts 0-11
    else // invalid month or amount value
        cout << "Invalid month or sales figure" << endl;
} // end function setSales

// print total annual sales (with the help of utility function)
void SalesPerson::printAnnualSales()
{
    
    //cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision( 2 ) << fixed
    << "\nThe total annual sales are: $"
    << totalAnnualSales() << endl; // call utility function
} // end function printAnnualSales

// private utility function to total annual sales
double SalesPerson::totalAnnualSales()
{
    double total = 0.0; // initialize total
    
    for ( int i = 0; i < monthsPerYear; i++ ) // summarize sales results
        total += sales[ i ]; // add month i sales to total
    
    return total;
} // end function totalAnnualSales

/*
int main(int argc, const char * argv[])
{

    // print my name and this assignment's title
    cout << "Lab 3A, Sales Person Program \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: G++\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    return 0;
}
 */
