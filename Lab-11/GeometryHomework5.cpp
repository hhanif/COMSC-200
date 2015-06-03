// Lab 11, Geometrey Homework Program
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

//Classes
class Square {
protected:
    const double square_side;
public:
    Square(const char* const token[4]):square_side(token[1]==0?0:atof(token[1]))
    {
    }
    void output(ostream&) const;
};

class Rectangle {
protected:
    const double rectangle_length;
    const double rectangle_width;
public:
    Rectangle(const char* const token[4]):rectangle_length(token[1] == 0?0:atof(token[1])), rectangle_width(token[2] == 0?0:atof(token[2]))
    {
        
    }
    void output(ostream&) const;
};
class Circle {
protected:
    const double circle_radius;
public:
    Circle(const char* const token[4]):circle_radius(token[1] == 0?0:atof(token[1]))
    {
        
    }
    void output(ostream&) const;
};
class Cube:public Square {
public:
    Cube(const char* const token[]):Square(token)
    {
    }
    void output(ostream&) const;
};
class Prism:public Rectangle {
    const double height;
public:
    Prism(const char* const token[]):Rectangle(token), height(token[3] == 0?0:atof(token[3]))
    {
    }
    void output(ostream&) const;
};
class Cylinder:public Circle {
    const double height;
public:
    Cylinder(const char* const token[]):Circle(token),height(token[2] == 0?0:atof(token[2]))
    {
    }
    void output(ostream&) const;
};

ostream& Reset(ostream&);
ostream& Set(ostream&);
void output(ostream&);
const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";
const double PI = 3.14159265;

int main()
{
    // print my name and this assignment's title
    cout << "Lab 4B, Geometrey Homework Program \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: G++\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    // create a file-reading object
    ifstream fin;
    const void *shape[100];
    int ShapeId[100];
    int ShapeIndex = 0;
    
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
                const Square* const s = new Square(token);
                shape[ShapeIndex] =s;
                ShapeId[ShapeIndex] = 1;
                ShapeIndex++;
            }
            //Print and Calculate Rectangle Values
            else if(strcmp(token[0],"RECTANGLE") == 0){
                const Rectangle* const r = new Rectangle(token);
                shape[ShapeIndex] = r;
                ShapeId[ShapeIndex] = 2;
                ShapeIndex++;
            }
            //Print and Calculate Circle Values
            else if(strcmp(token[0],"CIRCLE") == 0){
                const Circle* const c = new Circle(token);
                shape[ShapeIndex] = c;
                ShapeId[ShapeIndex] = 3;
                ShapeIndex++;
            }
            //Print and Calculate Cube Values
            else if(strcmp(token[0],"CUBE") == 0){
                const Cube* const cu = new Cube(token);
                shape[ShapeIndex] = cu;
                ShapeId[ShapeIndex] = 4;
                ShapeIndex++;
            }
            //Print and Calculate Rectangular Prism Values
            else if(strcmp(token[0],"PRISM") == 0){
                const Prism* const p = new Prism(token);
                shape[ShapeIndex] = p;
                ShapeId[ShapeIndex] = 5;
                ShapeIndex++;
            }
            //Print and Calculate Cylinder Values
            else if(strcmp(token[0],"CYLINDER") == 0){
                const Cylinder* const cyl = new Cylinder(token);
                shape[ShapeIndex] = cyl;
                ShapeId[ShapeIndex] = 6;
                ShapeIndex++;
            }
            else {
                cout<< token[0] << " Invalid Object Input" << endl;
            }
        }
    }
    
    fin.close();
    
    for(int a=0; a<ShapeIndex; a++){
        if(ShapeId[a] == 1) ((Square*)shape[a])->output(cout);
        else if(ShapeId[a] == 2) ((Rectangle*)shape[a])->output(cout);
        else if(ShapeId[a] == 3) ((Circle*)shape[a])->output(cout);
        else if(ShapeId[a] == 4) ((Cube*)shape[a])->output(cout);
        else if(ShapeId[a] == 5) ((Prism*)shape[a])->output(cout);
        else if(ShapeId[a] == 6) ((Cylinder*)shape[a])->output(cout);
    }
    for(int b=0; b<ShapeIndex; b++){
        if(ShapeId[b] == 1) delete((Square*)shape[b]);
        else if(ShapeId[b] == 2) delete((Rectangle*)shape[b]);
        else if(ShapeId[b] == 3) delete((Circle*)shape[b]);
        else if(ShapeId[b] == 4) delete((Cube*)shape[b]);
        else if(ShapeId[b] == 5) delete((Prism*)shape[b]);
        else if(ShapeId[b] == 6) delete((Cylinder*)shape[b]);
    }
    
    cout<<"All objects have been erased"<<endl;
}


//Function Definitions
void Square::output(ostream& print) const{
    double side = square_side;
    cout << Reset;
    print << "SQUARE Side = " << side;
    cout << Set;
    print << " Area = " << side * side << " Perimeter = " << side * 4 << endl;
    
}
void Rectangle::output(ostream& print) const{
    double Area = rectangle_length * rectangle_width;
    double Perimeter = (2 * rectangle_length) + (2 * rectangle_width);
    cout << Reset;
    print << "RECTANGLE Length = " << rectangle_length << " Width = " << rectangle_width;
    cout << Set;
    print << "Area = " << Area << " Perimeter = " << Perimeter << endl;
}
void Circle::output(ostream& print) const{
    double Area = circle_radius * PI * PI;
    double Circumference = circle_radius * PI * 2;
    cout << Reset;
    print << "CIRCLE Radius = " << circle_radius;
    cout << Set;
    print << "Area = " << Area << " Circumference = " << Circumference << endl;
}
void Cube::output(ostream& print) const{
    double SurfaceArea = (square_side * square_side) * 6;
    double Volume = square_side * square_side * square_side;
    cout << Reset;
    print << "CUBE = " << square_side;
    cout << Set;
    print << "Surface Area = " << SurfaceArea << " Volume = " << Volume << endl;
}
void Prism::output(ostream& print) const{
    double SurfaceArea = (2 * rectangle_length * rectangle_width) + (2 * rectangle_length * height) + (2 * rectangle_width * height);
    double Volume = height * rectangle_length * rectangle_width;
    cout << Reset;
    print << "PRISM height = " << height << " Length = " << rectangle_length << " Width = " << rectangle_width;
    cout << Set;
    print << "Surface Area = " << SurfaceArea << " Volume = " << Volume << endl;
}
void Cylinder::output(ostream& print) const{
    double SurfaceArea = (2 * PI * circle_radius * circle_radius) + (2 * PI * circle_radius * height);
    double Volume = PI * height * circle_radius * circle_radius;
    cout << Reset;
    print << "CYCLINDER Radius = " << circle_radius << " Height = " << height;
    cout << Set;
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
