// Lab 13, Geometrey Homework Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: G++
#include "stdafx.h"
#include "GeometryHomework.h"
#include <iostream>
using std::cout;
using std::endl;
using std::ios;
using std::ostream;
#include <iomanip>
using std::setprecision;


const double PI = 3.14159265;

//Function Definitions
void Square::output(ostream& print) const{
    double Area = Dimension1 * Dimension1;
    double Perimeter = Dimension1 * 4;
    print << Reset;
    print << "SQUARE Side = " << Dimension1;
    print << Set;
    print << " Area = " << Area << " Perimeter = " << Perimeter << endl;
    
}
void Rectangle::output(ostream& print) const{
    double Area = Dimension1 * Dimension2;
    double Perimeter = (2 * Dimension1) + (2 * Dimension2);
    print << Reset;
    print << "RECTANGLE Length = " << Dimension1 << " Width = " << Dimension2;
    print << Set;
    print << "Area = " << Area << " Perimeter = " << Perimeter << endl;
}
void Circle::output(ostream& print) const{
    double Area = Dimension1 * PI * PI;
    double Circumference = Dimension1 * PI * 2;
    print << Reset;
    print << "CIRCLE Radius = " << Dimension1;
    print << Set;
    print << "Area = " << Area << " Circumference = " << Circumference << endl;
}
void Cube::output(ostream& print) const{
    double SurfaceArea = (Dimension1 * Dimension1) * 6;
    double Volume = Dimension1 * Dimension1 * Dimension1;
    print << Reset;
    print << "CUBE = " << Dimension1;
    print << Set;
    print << "Surface Area = " << SurfaceArea << " Volume = " << Volume << endl;
}
void Prism::output(ostream& print) const{
    double SurfaceArea = (2 * Dimension1 * Dimension2) + (2 * Dimension1 * Dimension3) + (2 * Dimension2 * Dimension3);
    double Volume = Dimension1 * Dimension2 * Dimension3;
    print << Reset;
    print << "PRISM height = " << Dimension1 << " Length = " << Dimension2 << " Width = " << Dimension3;
    print << Set;
    print << "Surface Area = " << SurfaceArea << " Volume = " << Volume << endl;
}
void Cylinder::output(ostream& print) const{
    double SurfaceArea = (2 * PI * Dimension1 * Dimension1) + (2 * PI * Dimension1 * Dimension2);
    double Volume = PI * Dimension1 * Dimension1 * Dimension2;
    print << Reset;
    print << "CYCLINDER Radius = " << Dimension1 << " Height = " << Dimension2;
    print << Set;
    print << "Surface Area = " << SurfaceArea << " Volume = " << Volume << endl;
}

ostream& Reset(ostream& print)
{
    print.unsetf(ios::fixed|ios::showpoint);
    print << setprecision(6);
    return print;
}

ostream& Set(ostream& print)
{
    print.setf(ios::fixed|ios::showpoint);
    print << setprecision(2);
    return print;
}

ostream& operator<<(ostream& out, const Shape* s)
{
    s->output(out);
    return out;
}
