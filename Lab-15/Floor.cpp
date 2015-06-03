// Lab 14A, Elevator Simulation Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include "Floor.h"
#include "Rider.h"
#include "Elevator.h"


using std::endl;

bool Floor::isPreferredDirectionUp() const
{
    if(!(hasDownRiders()))
        return true;
    
    if(!(hasUpRiders()))
        return false;
    
    if(upRiders[0] < downRiders[0])
        return true;
    
    return false;
}
void Floor::addNewRider(const Rider& Rider){
    if(Rider.getDestination().getLocation()>this->getLocation())
    {
        upRiders.push_back(Rider);
    }
    else
    {
        downRiders.push_back(Rider);
    }
}

vector<Rider> Floor::removeUpRiders(int Capacity){
    vector<Rider> Leaving;
    if(hasUpRiders()){
        vector<Rider> Staying;
        for(int i=0; i < upRiders.size();i++)
        {
            if(Leaving.size()!= Capacity)
            {
                Leaving.push_back(upRiders[i]);
            }
            else
            {
                Staying.push_back(upRiders[i]);
            }
        }
        upRiders=Staying;
        
    }
    return Leaving;
}
vector<Rider> Floor::removeDownRiders(int Capacity){
    vector<Rider> Leaving;
    if(hasDownRiders())
    {
        vector<Rider> Staying;
        for(int i=0; i < downRiders.size();i++)
        {
            if(Leaving.size()!= Capacity)
            {
                Leaving.push_back(downRiders[i]);
            }
            else
            {
                Staying.push_back(downRiders[i]);
            }
        }
        downRiders=Staying;
    }
    return Leaving;
    
}
ostream &operator<<(ostream &print, const Floor &F)
{
    print<<"Floor Name is: ";
    print<<F.NAME;
    print<<endl;
    print<<"\nThe current number of Up-Riders waiting is: ";
    print<<F.upRiders.size();
    print<<endl;
    print<<"\nThe current number of Down-Riders waiting is: ";
    print<<F.downRiders.size();
    print<<endl;
    print<<"\nCurrent location of the Elevator is: ";
    print<<F.getLocation();
    print<<endl;
    return print;
}
