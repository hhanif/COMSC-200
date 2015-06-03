// Lab 13, Geometrey Homework Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: G++

#ifndef GEOMETRYHOMEWORK_H
#define GEOMETRYHOMEWORK_H
#include <iostream>
using std::ostream;


//Classes
class Shape{
protected:
    double const Dimension1;
    double const Dimension2;
    double const Dimension3;
public:
    Shape(const char* const token[])
    :Dimension1(token[1]==0?0:atof(token[1])),Dimension2(token[2]==0?0:atof(token[2])), Dimension3(token[3]==0?0:atof(token[3])){}
    virtual void output(ostream&) const = 0;
    virtual ~Shape() {};
};
ostream& operator<<(ostream&, const Shape*);

struct Square:public Shape{
    Square(const char* const token[]):Shape(token){}
    void output(ostream&) const;
};

struct Rectangle:public Shape{
    Rectangle(const char* const token[]):Shape(token){}
    void output(ostream&) const;
};

struct Circle:public Shape{
    Circle(const char* const token[]):Shape(token){}
    void output(ostream&) const;
};

struct Cube:public Square
{
    Cube(const char* const token[]):Square(token){}
    void output(ostream&) const;
};

struct Prism:public Rectangle
{
    Prism(const char* const token[]):Rectangle(token){}
    void output(ostream&) const;
};

struct Cylinder:public Circle
{
    Cylinder(const char* const token[]):Circle(token){}
    void output(ostream&) const;
};
ostream& Reset(ostream&);
ostream& Set(ostream&);


#endif
