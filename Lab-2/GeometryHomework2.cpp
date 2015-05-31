// Lab 2B, Geometrey Homework Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: G++

#include <iostream>
using std::cout;
using std::endl;
using std::ios;
//using std::cin;
#include <iomanip>
using std::setprecision;
#include <cstdlib>

#include <fstream>
using std::ifstream;

#include <cstring>

//Structures
struct Square {
    double square_side;
};

struct Rectangle {
    double rectangle_length;
    double rectangle_width;
};
struct Circle {
    double circle_radius;
};
struct Cube {
    double cube_side;
};
struct Prism {
    double prism_length;
    double prism_width;
    double prism_height;
};
struct Cylinder {
    double cylinder_radius;
    double cylinder_height;
};

void outputSquare(Square* square);
void outputRectangle(Rectangle* rectangle);
void outputCircle(Circle* circle);
void outputCube(Cube* cube);
void outputPrism(Prism* prism);
void outputCylinder(Cylinder* cylinder);


const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";
const double PI = 3.14159265;

int main()
{
    // print my name and this assignment's title
    cout << "Lab 2B, Geometrey Homework Program \n";
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
        if (token[0]) // zero if line is blank
        {
            for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
            {
                token[n] = strtok(0, DELIMITER); // subsequent tokens
                if (!token[n]) break; // no more tokens
            }
            
            //converts tokens to doubles
            double nums[MAX_TOKENS_PER_LINE-1];
            for(int i = 1; i < MAX_TOKENS_PER_LINE; i++){
                if(token[i] != NULL)
                    nums[i-1] = atof(token[i]);
                else
                    nums[i-1] = 0;
            }
            // process (print) the tokens
            for (int i = 0; i < n; i++)
            {
            // n = #of tokens
            //    cout << "Token[" << i << "] = " << token[i] << endl;
            //cout << endl;
            
            //Print and Calculate Square Values
            if(strcmp(token[0],"SQUARE")==0){
                    Square* s = new Square;
                    s->square_side = nums[0];
                    shape[ShapeIndex] =s;
                    ShapeId[ShapeIndex] = 1;
                    break;
                }
            //Print and Calculate Rectangle Values
            else if(strcmp(token[0],"RECTANGLE") == 0){
                Rectangle* r = new Rectangle;
                r->rectangle_length = nums[0];
                r->rectangle_width = nums[0];
                shape[ShapeIndex] = r;
                ShapeId[ShapeIndex] = 2;
                break;
            }
            //Print and Calculate Circle Values
            else if(strcmp(token[0],"CIRCLE") == 0){
                Circle* c = new Circle;
                c->circle_radius = nums[0];
                shape[ShapeIndex] = c;
                ShapeId[ShapeIndex] = 3;
                break;
            }
            //Print and Calculate Cube Values
            else if(strcmp(token[0],"CUBE") == 0){
                Cube* cu = new Cube;
                cu->cube_side = nums[0];
                shape[ShapeIndex] = cu;
                ShapeId[ShapeIndex] = 4;
                break;
            }
            //Print and Calculate Rectangular Prism Values
            else if(strcmp(token[0],"PRISM") == 0){
                Prism* p = new Prism;
                p->prism_length = nums[0];
                p->prism_height = nums[0];
                p->prism_width = nums[0];
                shape[ShapeIndex] = p;
                ShapeId[ShapeIndex] = 5;
                break;
            }
            //Print and Calculate Cylinder Values
            else if(strcmp(token[0],"CYCLINDER") == 0){
                Cylinder* cyl = new Cylinder;
                cyl->cylinder_radius = nums[0];
                cyl->cylinder_height = nums[0];
                shape[ShapeIndex] = cyl;
                ShapeId[ShapeIndex] = 6;
                break;
            }
            else {
                cout<< token[0] << " Invalid Object Input" << endl;
                ShapeIndex--;
                break;
            }
            }
        }
        ShapeIndex++;
    }
    fin.close();
    
    for(int a=0; a<ShapeIndex; a++){
        if(ShapeId[a] == 1) outputSquare((Square*)shape[a]);
        else if(ShapeId[a] == 2) outputRectangle((Rectangle*)shape[a]);
        else if(ShapeId[a] == 3) outputCircle((Circle*)shape[a]);
        else if(ShapeId[a] == 4) outputCube((Cube*)shape[a]);
        else if(ShapeId[a] == 5) outputPrism((Prism*)shape[a]);
        else if(ShapeId[a] == 6) outputCylinder((Cylinder*)shape[a]);
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
void outputSquare(Square* square){
    double square_side = square->square_side;
    cout.unsetf(ios::fixed|ios::showpoint);
    cout << setprecision(6);
    cout <<"SQUARE side="<< square_side;
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(2);
    cout <<" area = " << square_side * square_side << " perimeter = " << square_side * 4 <<endl;
    
}
void outputRectangle(Rectangle* rectangle){
    double rectangle_length = rectangle->rectangle_length;
    double rectangle_width = rectangle->rectangle_width;
    cout.unsetf(ios::fixed|ios::showpoint);
    cout << setprecision(6);
    cout << "RECTANGLE length =" <<rectangle_length<<" width = " << rectangle_width;
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(2);
    cout <<" area = " << rectangle_length * rectangle_width << " perimeter = " << (2 * rectangle_length) + (2 * rectangle_width) << endl;
}
void outputCircle(Circle* circle){
    double circle_radius = circle->circle_radius;
    cout.unsetf(ios::fixed|ios::showpoint);
    cout << setprecision(6);
    cout <<" CIRCLE radius = " << circle_radius;
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(2);
    cout <<"area = " << (PI) * ((circle_radius) * (circle_radius)) << " circumference = " << 2 * PI * circle_radius <<endl;
    
}
void outputCube(Cube* cube){
    double cube_side = cube->cube_side;
    cout.unsetf(ios::fixed|ios::showpoint);
    cout << setprecision(6);
    cout <<"CUBE side = " << cube_side;
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(2);
    cout<<" surface area = " << 6 * (cube_side * cube_side) << " volume = " << cube_side * cube_side * cube_side <<endl;
    
}
void outputPrism(Prism* prism){
    double prism_length = prism->prism_length;
    double prism_width = prism->prism_width;
    double prism_height = prism->prism_width;
    cout.unsetf(ios::fixed|ios::showpoint);
    cout << setprecision(6);
    cout <<"PRISM length = "<<prism_length << " width = " << prism_width << " height = " << prism_height;
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(2);
    cout <<" surface Area = " << (2*prism_length*prism_width) + (2*prism_width*prism_height) + (2*prism_length*prism_height) << " volume = " << prism_length*prism_width*prism_height <<endl;
    
}
void outputCylinder(Cylinder* cylinder){
    double cylinder_radius = cylinder->cylinder_radius;
    double cylinder_height = cylinder->cylinder_height;
    cout.unsetf(ios::fixed|ios::showpoint);
    cout << setprecision(6);
    cout <<"CYLINDER radius = " << cylinder_radius << " height = " << cylinder_height;
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(2);
    cout <<" surface area = " << 2*(PI)*(cylinder_radius*cylinder_radius) + 2*(PI)*(cylinder_radius*cylinder_height) << " volume = " << (PI) * (cylinder_radius*cylinder_radius) * cylinder_height << endl;
    
}
