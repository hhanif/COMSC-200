// Lab 16, Elevator Simulation Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <stdio.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstdlib>
#include <ctime>
#include <cmath>

#include "Building.h"

int getArrivalsForThisSecond(double);

int main()
{
    srand(time(0)); rand(); // requires cstdlib and ctime
    Building building;
    
    for (int i = 0; ; i++)
    {
        cout << building.step(getArrivalsForThisSecond(.1));
        cout << endl;
        
        if (!(i % 10)) // pause every 10 seconds
        {
            cout << "Press ENTER to continue, X-ENTER to quit...\n";
            if (cin.get() > 31) break;
        }
    }
    cout << "DONE: All riders should be gone, and all elevators idle\n";
}

int getArrivalsForThisSecond(double averageRiderArrivalRate)
{
    int arrivals = 0;
    double probOfnArrivals = exp(-averageRiderArrivalRate); // for n=0 -- requires cmath
    for(double randomValue = (rand() % 1000) / 1000.0; // requires cstdlib AND srand in main
        (randomValue -= probOfnArrivals) > 0.0;
        probOfnArrivals *= averageRiderArrivalRate / ++arrivals);
    return arrivals;
}
