// Lab 9B, Elevator Simulation Program
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
