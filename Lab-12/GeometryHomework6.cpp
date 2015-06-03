// Lab 12, Geometrey Homework Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: G++

#include <cstdlib>
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;
using std::ios;
using std::ostream;
#include <iomanip>
using std::setprecision;
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;
//Classes
class Shape{
protected:
    double const Dimension1;
    double const Dimension2;
    double const Dimension3;
public:
    Shape(const char* const[]);
    virtual void output(ostream&) const = 0;
    virtual ~Shape() {};
};

Shape::Shape(const char* const token[])
:Dimension1(token[1]==0?0:atof(token[1])),Dimension2(token[2]==0?0:atof(token[2])), Dimension3(token[3]==0?0:atof(token[3])){}


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
const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";
const double PI = 3.14159265;

int main()
{
    // print my name and this assignment's title
    cout << "Lab 12, Geometrey Homework Program \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: G++\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    double Dimension[MAX_TOKENS_PER_LINE] = {};
    vector <Shape*> Shapes;
    // create a file-reading object
    ifstream fin;
    
    fin.open("geo.txt"); // open a file
    if (!fin.good())
    {
        cout << "geo.txt did not open\n";
        return 1; // exit if file not found
    }
    else
    {
        cout << "Opened file successfully\n";
    }
    
    // read each line of the file
    while (!fin.eof())
    {
        // read an entire line into memory
        char buf[MAX_CHARS_PER_LINE];
        fin.getline(buf, MAX_CHARS_PER_LINE);
        
        // parse the line into blank-delimited tokens
        int n = 0; // a for-loop index
        
        // array to store memory addresses of the tokens in buf
        const char* token[MAX_TOKENS_PER_LINE] = {}; // initialize to 0
        
        // parse the line
        token[0] = strtok(buf, DELIMITER); // first token
        if (token[n]) // zero if line is blank
        {
            for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
            {
                token[n] = strtok(0, DELIMITER); // subsequent tokens
                if (!token[n]) break; // no more tokens
            }
            //Print and Calculate Square Values
            if(strcmp(token[0],"SQUARE")==0){
                Shapes.push_back(new Square(token));
            }
            //Print and Calculate Rectangle Values
            else if(strcmp(token[0],"RECTANGLE") == 0){
                Shapes.push_back(new Rectangle(token));
            }
            //Print and Calculate Circle Values
            else if(strcmp(token[0],"CIRCLE") == 0){
                Shapes.push_back(new Circle(token));
            }
            //Print and Calculate Cube Values
            else if(strcmp(token[0],"CUBE") == 0){
                Shapes.push_back(new Cube(token));
            }
            //Print and Calculate Rectangular Prism Values
            else if(strcmp(token[0],"PRISM")==0){
                Shapes.push_back(new Prism(token));
            }
            //Print and Calculate Cylinder Values
            else if(strcmp(token[0],"CYLINDER") == 0){
                Shapes.push_back(new Cylinder(token));
            }
            else {
                cout<< token[0] << " Invalid Object Input" << endl;
            }
        }
    }
    
    fin.close();
    
    for(vector <Shape*>::const_iterator it = Shapes.begin(); it != Shapes.end(); it++)
    {
        (*it)->output(cout);
    }
    for(vector<Shape*>::const_iterator it = Shapes.begin(); it != Shapes.end(); it++)
    {
        delete *it;
    }
    
    cout<<"All objects have been erased"<<endl;
}


//Function Definitions
void Square::output(ostream& print) const{
    double Area = Dimension1 * Dimension1;
    double Perimeter = Dimension1 * 4;
    cout << Reset;
    print << "SQUARE Side = " << Dimension1;
    cout << Set;
    print << " Area = " << Area << " Perimeter = " << Perimeter << endl;
    
}
void Rectangle::output(ostream& print) const{
    double Area = Dimension1 * Dimension2;
    double Perimeter = (2 * Dimension1) + (2 * Dimension2);
    cout << Reset;
    print << "RECTANGLE Length = " << Dimension1 << " Width = " << Dimension2;
    cout << Set;
    print << "Area = " << Area << " Perimeter = " << Perimeter << endl;
}
void Circle::output(ostream& print) const{
    double Area = Dimension1 * PI * PI;
    double Circumference = Dimension1 * PI * 2;
    cout << Reset;
    print << "CIRCLE Radius = " << Dimension1;
    cout << Set;
    print << "Area = " << Area << " Circumference = " << Circumference << endl;
}
void Cube::output(ostream& print) const{
    double SurfaceArea = (Dimension1 * Dimension1) * 6;
    double Volume = Dimension1 * Dimension1 * Dimension1;
    cout << Reset;
    print << "CUBE = " << Dimension1;
    cout << Set;
    print << "Surface Area = " << SurfaceArea << " Volume = " << Volume << endl;
}
void Prism::output(ostream& print) const{
    double SurfaceArea = (2 * Dimension1 * Dimension2) + (2 * Dimension1 * Dimension3) + (2 * Dimension2 * Dimension3);
    double Volume = Dimension1 * Dimension2 * Dimension3;
    cout << Reset;
    print << "PRISM height = " << Dimension1 << " Length = " << Dimension2 << " Width = " << Dimension3;
    cout << Set;
    print << "Surface Area = " << SurfaceArea << " Volume = " << Volume << endl;
}
void Cylinder::output(ostream& print) const{
    double SurfaceArea = (2 * PI * Dimension1 * Dimension1) + (2 * PI * Dimension1 * Dimension2);
    double Volume = PI * Dimension1 * Dimension1 * Dimension2;
    cout << Reset;
    print << "CYCLINDER Radius = " << Dimension1 << " Height = " << Dimension2;
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
