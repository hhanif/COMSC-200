// Lab 9A, Array Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: G++
// Fig. 11.6: Array.h
// Array class definition with overload operators
#ifndef Array_h
#define Array_h

#include<iostream>
using std::ostream;
using std::istream;

class Array
{
    friend ostream &operator<<( ostream &, const Array & );
    friend istream &operator>>( istream &, Array & );
public:
    Array (int = 10); // default constructor
    Array( const Array & ); // copy constructor
    ~Array(); // destructor
    int getSize() const; // return size
    
    const Array &operator=(const Array & ); // assignment operator
    bool operator==( const Array & ) const; // equality operator
    
    //inequality operator; returns opposite of == operator
    bool operator!=( const Array &right ) const
    {
        return ! (*this == right); //invokes Array::operator==
    } // end function operator !=
    
    //subscript operator for non-const objects return modifiable lvalue
    int &operator[](int);
    
    //subscript operator for const objects returns rvalue
    int operator[](int)const;
private:
    int size; //pointer-based array size
    int *ptr; //pointer to first element of pointer-based array
}; // end class Array


#endif
