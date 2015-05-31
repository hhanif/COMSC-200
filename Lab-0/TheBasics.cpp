// Lab 0c, The Console Programming Basics Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <iostream>
using namespace std;
#include <iomanip>
int main()
{
    // print my name and this assignment's title
    cout << "Lab 0c, The Console Programming Basics Program \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    //Have user enter data and then calculate users age in a year and the degrees in celcius
    int age;
    string name;
    double temperature;
    string city;
    double celcius;
    char buf[100];
    
    cout << "Enter your age:" <<endl;
    cin >> buf; age = atoi(buf);
    cin.ignore(1000, 10);
    cout << "Enter your name:" <<endl;
    getline (cin, name);
    cout << "Enter the temperature outside right now (degrees F):" <<endl;
    cin >> buf; temperature = atof(buf);
    cin.ignore(1000, 10);

    cout << "What city are you in right now?" <<endl;
    getline (cin, city);
    
    //Converting the inputted temperature from farenheit to celcius
    celcius = (5.0 / 9.0) * (temperature - 32.0);
    
    
    //Printing out the final calculations
    cout << name << " is " << age << " years old now, and will be "<< age + 1 <<" a year from now.";
    cout << endl << "It's " << temperature << " degrees in " << city << " -- that's ";
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(1);
    cout << celcius<< " degrees C."<<endl;

}
