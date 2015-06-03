// Lab 10B, Elevator Simulation Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: G++

#include "Elevator.h"
#include "Floor.h"

int Elevator::elevatorID = 0;
const int Elevator::IDLE = 0;
const int Elevator::UP = 1;
const int Elevator::DOWN = -1;

//constructor
Elevator::Elevator(const int Max, const int IPS, const Floor& Start):ID(elevatorID), capacity(Max), speed(IPS),toFloor(0)
{
	location = Start.getLocation();
	direction = IDLE;
	doorOpen = true;
}

bool Elevator::isNearDestination() const
{
	double Distance = (toFloor -> getLocation() - location);
    
	if(Distance < 0)
	{
		Distance *= -1;
	}
    
	return (Distance <= speed);
}

void Elevator::moveToDestinationFloor()
{
	if(hasADestination())
	{
		location = toFloor -> getLocation();
	}
}

ostream& operator<<(ostream& Output, const Elevator& e)
{
	Output << "Elevator is located at ";
    Output << e.getLocation();
    Output << " inches from the ground.\n";
    
	if(e.isIdle())
    {
		Output <<"The Elevator is idle.\n";
	}
	else if(e.isDirectionUp())
	{
		Output <<"The Elevator is going up.\n";
	}
	else if(e.isDirectionDown())
	{
		Output <<"The Elevator is going down.\n";
	}
    
	if(e.isDoorOpen())
	{
		Output <<"The Door is open.\n";
	}
	else
	{
		Output <<"The Door is closed.\n";
	}
	return Output;
}

vector<Rider> Elevator::removeRidersForDestinationFloor()
{
    vector<Rider> Leave;
    
    if(Riders.size()!=0)
    {
        vector<Rider> Stay;
        
        for(int i=0; i<Riders.size();i++)
        {
            if(toFloor==&Riders[i].getDestination())
                Leave.push_back(Riders[i]);
            else
                Stay.push_back(Riders[i]);
        }
        Riders = Stay;
    }
    return Leave;
}

void Elevator::addRiders(const vector<Rider>& r)
{
    vector<Rider>::const_iterator i;
    for(i=r.begin(); i != r.end(); i++)
        if(Riders.size()<capacity)
            Riders.push_back(*i);
}
void Elevator::setDestinationBasedOnRiders()
{
    if(!hasRiders())
        return;
    
    int Distance = 1;
    
    for(int i=0;i<Riders.size();i++)
    {
        Distance = getLocation()-Riders[i].getDestination().getLocation();
        
        Distance=abs(Distance);
        if(getLocation() - Riders[i].getDestination().getLocation() < 0 || getLocation()-Riders[i].getDestination().getLocation() > Distance)
            Distance = getLocation()-Riders[i].getDestination().getLocation();
        
        setDestination(&Riders[i].getDestination());
    }
}
