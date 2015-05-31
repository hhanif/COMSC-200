// Lab 1B, Geometrey Homework Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: G++

#include <iostream>
using std::cout;
using std::endl;
using std::ios;
using std::cin;
#include <iomanip>
using std::setprecision;
#include <cstdlib>

#include <fstream>
using std::ifstream;

#include <cstring>


const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";

int main()
{
    // print my name and this assignment's title
    cout << "Lab 1B, Geometrey Homework Program \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: G++\n";
    
    // create a file-reading object
    ifstream fin;
    fin.open("geo.txt"); // open a file
    if (!fin.good())
    {
        cout << "geo.txt did not open\n";
        return 1; // exit if file not found
    } else
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
        //for (int i = 0; i < n; i++) // n = #of tokens
        //    cout << "Token[" << i << "] = " << token[i] << endl;
        //cout << endl;
        
        
        //Print and Calculate Square Values
        if(strcmp(token[0],"SQUARE")==0){
            double square_side = nums[0];
            cout.unsetf(ios::fixed|ios::showpoint);
            cout << setprecision(6);
            cout <<"SQUARE side="<< square_side;
            cout.setf(ios::fixed|ios::showpoint);
            cout << setprecision(2);
            cout <<" area = " << square_side * square_side << " perimeter = " << square_side * 4 <<endl;
            
        }
        //Print and Calculate Rectangle Values
         else if(strcmp(token[0],"RECTANGLE") == 0){
            double rectangle_length = nums[0];
            double rectangle_width = nums[1];
            cout.unsetf(ios::fixed|ios::showpoint);
            cout << setprecision(6);
            cout << "RECTANGLE length =" <<rectangle_length<<" width = " << rectangle_width;
            cout.setf(ios::fixed|ios::showpoint);
            cout << setprecision(2);
            cout <<" area = " << rectangle_length * rectangle_width << " perimeter = " << (2 * rectangle_length) + (2 * rectangle_width) << endl;
        }
        //Print and Calculate Circle Values
        else if(strcmp(token[0],"CIRCLE") == 0){
            double circle_radius = nums[0];
            cout.unsetf(ios::fixed|ios::showpoint);
            cout << setprecision(6);
            cout <<" CIRCLE radius = " << circle_radius;
            cout.setf(ios::fixed|ios::showpoint);
            cout << setprecision(2);
            cout <<"area = " << (3.14) * ((circle_radius) * (circle_radius)) << " circumference = " << 2 * 3.14 * circle_radius <<endl;
        }
        //Print and Calculate Cube Values
        else if(strcmp(token[0],"CUBE") == 0){
            double cube_side = nums[0];
            cout.unsetf(ios::fixed|ios::showpoint);
            cout << setprecision(6);
            cout <<"CUBE side = " << cube_side;
            cout.setf(ios::fixed|ios::showpoint);
            cout << setprecision(2);
            cout<<" surface area = " << 6 * (cube_side * cube_side) << " volume = " << cube_side * cube_side * cube_side <<endl;
    }
        //Print and Calculate Rectangular Prism Values
        else if(strcmp(token[0],"PRISM")==0){
            double prism_length = nums[0];
            double prism_width = nums[1];
            double prism_height = nums[2];
            cout.unsetf(ios::fixed|ios::showpoint);
            cout << setprecision(6);
            cout <<"PRISM length = "<<prism_length << " width = " << prism_width << " height = " << prism_height;
            cout.setf(ios::fixed|ios::showpoint);
            cout << setprecision(2);
            cout <<" surface Area = " << (2*prism_length*prism_width) + (2*prism_width*prism_height) + (2*prism_length*prism_height) << " volume = " << prism_length*prism_width*prism_height <<endl;
        }
        //Print and Calculate Cylinder Values
        else if(strcmp(token[0],"CYLINDER") == 0){
            double cylinder_radius = nums[0];
            double cylinder_height = nums[1];
            cout.unsetf(ios::fixed|ios::showpoint); // undoes "fixed" and "showpoint"
            cout << setprecision(6);
            cout <<"CYLINDER radius = " << cylinder_radius << " height = " << cylinder_height;
            cout.setf(ios::fixed|ios::showpoint);
            cout << setprecision(2);
            cout <<" surface area = " << 2*(3.14)*(cylinder_radius*cylinder_radius) + 2*(3.14)*(cylinder_radius*cylinder_height) << " volume = " << (3.14) * (cylinder_radius*cylinder_radius) * cylinder_height << endl;
        }
        else
            cout<< token[0] << " Invalid Object Input" << endl;
}
    }
}
