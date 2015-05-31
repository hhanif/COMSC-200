// Lab 5B, Shortest Route Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: G++

#include <iostream>
using std::cout;
using std::endl;
using std::ios;
using std::ostream;

class Leg
{
private:
	const char* const StartCity;
	const char* const EndCity;
	const double distance;
public:
	Leg(const char* const StartLocation,const char* const EndLocation, const double miles):StartCity(StartLocation),EndCity(EndLocation), distance(miles){};
	friend void outputLeg(ostream&, const Leg&);
};
void outputLeg(ostream&, const Leg&);

int main()
{
    // print my name and this assignment's title
    cout << "Lab 5B, Shortest Route Program \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: G++\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    //Create Legs
    Leg a("San Francisco", "San Jose", 20.0);
    outputLeg(cout, a);
    Leg b("San Jose", "Los Angeles", 340.0);
    outputLeg(cout, b);
    Leg c("Los Angeles", "San Diego", 120.0);
    outputLeg(cout, c);
    Leg d("San Diego", "Seattle", 1255.0);
    outputLeg(cout, d);
    Leg e("Seattle", "Santa Clara", 839.0);
    outputLeg(cout, e);
}

//Print Leg
void outputLeg(ostream& print, const Leg& drive){
    print<< drive.StartCity;
    print<< " to ";
    print<< drive.EndCity;
    print<< ", ";
    print<< drive.distance;
    print<< " miles." <<endl;
    
}
