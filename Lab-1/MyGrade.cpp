// Lab 1A, Class average program with counter-controlled repetition
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

// Fig. 3.8: fig_08.cpp
//Class average program with counter-controlled repetition
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main(int argc, const char * argv[])
{
    // print my name and this assignment's title
    cout << "Lab 1A, Class average program with counter-controlled repetition \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";

    int total; //sum of grades entered by user
    int gradeCounter; //number of the grade to be entered next
    int grade; //grade value entered by user
    int average; //average of grades
    char buf[100];

    //inititalization phase
    total = 0; //intitialize total
    gradeCounter = 1; //initialize loop counter
    //processing phase
    while (gradeCounter <= 10) //loop 10 times
    {
        cout << "Enter grade: ";//prompt for input
        cin >> buf; grade = atoi(buf);
        total = total + grade; // add grade to total
        gradeCounter = gradeCounter + 1; //increment counter by 1
    } //end while
    
    //termination phase
    average = total / 10; //integer division yields integer result
    
    //display total and average of grades
    cout << "\nTotal of all 10 grades is " << total << endl;
    cout << "Class average is " << average << endl;

} //end main
