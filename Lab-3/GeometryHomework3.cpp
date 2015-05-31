// Lab 3B, Geometrey Homework Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: G++

#include <iostream>
using std::cout;
using std::endl;
using std::ios;
#include <iomanip>
using std::setprecision;
#include <cstdlib>

#include <fstream>
using std::ifstream;

#include <cstring>

//Classes
class Square {
private:
    double square_side;
public:
    Square(const char* token[4]){this->square_side = token[1]==0?0:atof(token[1]);}
    void output() const;
};

class Rectangle {
private:
    double rectangle_length;
    double rectangle_width;
public:
    Rectangle(const char* token[4]);
    void output() const;
};

Rectangle::Rectangle(const char* token[4])
{
    this->rectangle_length = token[1] == 0?0:atof(token[1]);
    this->rectangle_width = token[2] == 0?0:atof(token[2]);
}

class Circle {
private:
    double circle_radius;
public:
    Circle(const char* token[4]){ this->circle_radius = token[1] == 0?0:atof(token[1]);}
    void output() const;
};
class Cube {
private:
    double cube_side;
public:
    Cube(const char* token[4]){this->cube_side = token[1] == 0?0:atof(token[1]);}
    void output() const;
};
class Prism {
private:
    double prism_length;
    double prism_width;
    double prism_height;
public:
    Prism(const char* token[4]);
    void output() const;
};
Prism::Prism(const char* token[4]){
    this->prism_length = token[1] == 0?0:atof(token[1]);
    this->prism_width = token[2] == 0?0:atof(token[2]);
    this->prism_height = token[3] == 0?0:atof(token[3]);
}
class Cylinder {
private:
    double cylinder_radius;
    double cylinder_height;
public:
    Cylinder(const char* token[4]);
    void output() const;
};
Cylinder::Cylinder(const char* token[4]){
    this->cylinder_radius = token[1] == 0?0:atof(token[1]);
    this->cylinder_height = token[2] == 0?0:atof(token[2]);
}



const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";
const double PI = 3.14159265;

int main()
{
    // print my name and this assignment's title
    cout << "Lab 3B, Geometrey Homework Program \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: G++\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    // create a file-reading object
    ifstream fin;
    void *shape[100];
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
                Square* s = new Square(token);
                shape[ShapeIndex] =s;
                ShapeId[ShapeIndex] = 1;
                ShapeIndex++;
            }
            //Print and Calculate Rectangle Values
            else if(strcmp(token[0],"RECTANGLE") == 0){
                Rectangle* r = new Rectangle(token);
                shape[ShapeIndex] = r;
                ShapeId[ShapeIndex] = 2;
                ShapeIndex++;
            }
            //Print and Calculate Circle Values
            else if(strcmp(token[0],"CIRCLE") == 0){
                Circle* c = new Circle(token);
                shape[ShapeIndex] = c;
                ShapeId[ShapeIndex] = 3;
                ShapeIndex++;
            }
            //Print and Calculate Cube Values
            else if(strcmp(token[0],"CUBE") == 0){
                Cube* cu = new Cube(token);
                shape[ShapeIndex] = cu;
                ShapeId[ShapeIndex] = 4;
                ShapeIndex++;
            }
            //Print and Calculate Rectangular Prism Values
            else if(strcmp(token[0],"PRISM") == 0){
                Prism* p = new Prism(token);
                shape[ShapeIndex] = p;
                ShapeId[ShapeIndex] = 5;
                ShapeIndex++;
            }
            //Print and Calculate Cylinder Values
            else if(strcmp(token[0],"CYLINDER") == 0){
                //cout << "dis some cylinder typa shit" << endl;
                Cylinder* cyl = new Cylinder(token);
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
        if(ShapeId[a] == 1) ((Square*)shape[a])->output();
        else if(ShapeId[a] == 2) ((Rectangle*)shape[a])->output();
        else if(ShapeId[a] == 3) ((Circle*)shape[a])->output();
        else if(ShapeId[a] == 4) ((Cube*)shape[a])->output();
        else if(ShapeId[a] == 5) ((Prism*)shape[a])->output();
        else if(ShapeId[a] == 6) ((Cylinder*)shape[a])->output();
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
void Square::output() const{
    cout.unsetf(ios::fixed|ios::showpoint);
    cout << setprecision(6);
    cout <<"SQUARE side="<< square_side;
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(2);
    cout <<" area = " << square_side * square_side << " perimeter = " << square_side * 4 <<endl;
    
}
void Rectangle::output() const{
    cout.unsetf(ios::fixed|ios::showpoint);
    cout << setprecision(6);
    cout << "RECTANGLE length =" <<rectangle_length<<" width = " << rectangle_width;
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(2);
    cout <<" area = " << rectangle_length * rectangle_width << " perimeter = " << (2 * rectangle_length) + (2 * rectangle_width) << endl;
}
void Circle::output() const{
    cout.unsetf(ios::fixed|ios::showpoint);
    cout << setprecision(6);
    cout <<" CIRCLE radius = " << circle_radius;
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(2);
    cout <<"area = " << (PI) * ((circle_radius) * (circle_radius)) << " circumference = " << 2 * PI * circle_radius <<endl;
    
}
void Cube::output() const{
    cout.unsetf(ios::fixed|ios::showpoint);
    cout << setprecision(6);
    cout <<"CUBE side = " << cube_side;
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(2);
    cout<<" surface area = " << 6 * (cube_side * cube_side) << " volume = " << cube_side * cube_side * cube_side <<endl;
    
}
void Prism::output() const{
    cout.unsetf(ios::fixed|ios::showpoint);
    cout << setprecision(6);
    cout <<"PRISM length = "<<prism_length << " width = " << prism_width << " height = " << prism_height;
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(2);
    cout <<" surface Area = " << (2*prism_length*prism_width) + (2*prism_width*prism_height) + (2*prism_length*prism_height) << " volume = " << prism_length*prism_width*prism_height <<endl;
    
}
void Cylinder::output() const{
    cout.unsetf(ios::fixed|ios::showpoint);
    cout << setprecision(6);
    cout <<"CYLINDER radius = " << cylinder_radius << " height = " << cylinder_height;
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(2);
    cout <<" surface area = " << 2*(PI)*(cylinder_radius*cylinder_radius) + 2*(PI)*(cylinder_radius*cylinder_height) << " volume = " << (PI) * (cylinder_radius*cylinder_radius) * cylinder_height << endl;
    
}
