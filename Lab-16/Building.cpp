// Lab 15, Elevator Simulation Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include "Rider.h"
#include "Elevator.h"
#include "Floor.h"
#include "Building.h"

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
#include <stdlib.h>
#include <vector>
using std::vector;

Building::Building() : SimulationTime(0)
{
    Floors.push_back(new Floor(100, "Ground Floor"));
    Floors.push_back(new Floor(200, "First Floor"));
    Floors.push_back(new Floor(300, "Second Floor"));
    Floors.push_back(new Floor(400, "Third Floor"));
    Floors.push_back(new Floor(500, "Fourth Floor"));
    
    Elevators.push_back(new Elevator(12,5,*Floors[1]));
    Elevators.push_back(new Elevator(12,5,*Floors[1]));
}

Building& Building::step(int Cap)
{
    for(int i = 0; i < Cap; i++)
    {
        int TopFloor = getFloorCount();
        int FirstFloor;
        int LastFloor;
        getDifferentInts(TopFloor, FirstFloor, LastFloor);
        Floors[FirstFloor]->addNewRider(Rider(*Floors[LastFloor]));
    }
    
    for(int i = 0; i < getElevatorCount(); i++)
    {
        if(getElevator(i).isDoorOpen() == false)
        {
            if(getElevator(i).isNearDestination() == false)
            {
                if(getElevator(i).isDirectionUp() == true)
                {
                    Elevators[i]->moveUp();
                }
                else
                {
                    Elevators[i]->moveDown();
                }
            }
            
            else
            {
                Elevators[i]->moveToDestinationFloor();
                Elevators[i]->openDoor();
                Elevators[i]->removeRidersForDestinationFloor();
                
                Floor* Pointer;
                const_cast<const Floor*&>(Pointer) = &getElevator(i).getDestination();
                
                if(getElevator(i).getRiderCount() == 0)
                {
                    if(Pointer->isPreferredDirectionUp() == true)
                        Elevators[i]->setDirectionUp();
                    else
                        Elevators[i]->setDirectionDown();
                }
                
                if(getElevator(i).getAvailableSpace() > 0 && Elevators[i]->isDoorOpen() == true)
                {
                    
                    if(getElevator(i).isDirectionUp() == true)
                    {
                        Elevators[i]->addRiders(Pointer->removeUpRiders(Elevators[i]->getAvailableSpace()));
                    }
                    else
                    {
                        Elevators[i]->addRiders(Pointer->removeDownRiders(Elevators[i]->getAvailableSpace()));
                    }
                }
                
                Elevators[i]->setDestinationBasedOnRiders();
                
            }
            
            
        }
        
        else
        {
            if(getElevator(i).hasRiders() == true)
            {
                Elevators[i]->closeDoor();
            }
            else
            {
                Elevators[i]->setIdle();
            }
        }
        
    }
    
    
    for(int i = 0; i < getFloorCount();i++)
    {
        if(getFloor(i).hasRidersWaiting() == false)
        {
            continue;
        }
        for(int a = 0; a < getElevatorCount(); a++)
        {
            
            int CurrentLocation = Elevators[a]->getLocation() - Floors[i]->getLocation();
            
            if(getElevator(a).isIdle() == true)
            {
                
                if(CurrentLocation >= 0)
                {
                    Elevators[a]->setDirectionDown();
                    Elevators[a]->setDestination(Floors[i]);
                    Elevators[a]->closeDoor();
                }
                
                else
                {
                    Elevators[a]->setDirectionUp();
                    Elevators[a]->setDestination(Floors[i]);
                    Elevators[a]->closeDoor();
                }
            }
            
            else if(getFloor(i).hasUpRiders() == true && getElevator(a).isDirectionUp() == true)
            {
                double DistancetoFloor = getElevator(a).getDestination().getLocation() - getFloor(i).getLocation();
                if (DistancetoFloor > 0 && CurrentLocation < 0){
                    Elevators[a]->setDestination(&(getFloor(i)));
                }
            }
            
            else if(getFloor(i).hasUpRiders() == true && getElevator(a).isDirectionUp() == true)
            {
                double DistancetoFloor = getElevator(a).getDestination().getLocation() - getFloor(i).getLocation();
                if (DistancetoFloor < 0 && CurrentLocation > 0){
                    Elevators[a]->setDestination(&(getFloor(i)));
                }
            }
            
        }
    }
    
    SimulationTime++;
    return *this;
}

Building::~Building()
{
    for(int i=0; i<getFloorCount();i++)
        delete Floors[i];
    for(int i=0; i<getElevatorCount(); i++)
        delete Elevators[i];
}

void Building::getDifferentInts(int max, int& a, int& b)
{
    do
    {
        a = rand() % max; // range is 0 to (max-1)
        b = rand() % max; // range is 0 to (max-1)
    } while (a == b); // try again if they are the same
}

ostream& operator<<(ostream& Output, const Building& X)
{
    Output<< "The Time in seconds is: ";
    Output<< X.SimulationTime;
    Output<< endl;
    
    for(int i = 0; i < X.Elevators.size(); i++)
    {
        Output<<"Elevator Number: ";
        Output<< i + 1;
        Output<<endl;
        Output<< *X.Elevators[i];
        Output<<endl;
    }

    for(int i = 0; i< X.Floors.size(); i++)
    {
        if(X.getFloor(i).hasRidersWaiting())
            Output<< *X.Floors[i];
    }

    return Output;
}
