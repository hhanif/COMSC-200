// Lab 15, Elevator Simulation Program
// Programmer: Haris Hanif
// Editor(s) used: Sublime Text 2
// Compiler(s) used: G++

#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
using std::ostream;
#include <vector>
using std::vector;

class Elevator;
class Floor;

class Building{
public:
    
    Building();
    
    int getFloorCount() const{return (Floors.size());} // return #of floors in the vector of Floor*'s
    int getElevatorCount() const{return (Elevators.size());} // return #of elevators in the vector of Elevator*'s
    const Floor& getFloor(int index) const{return *Floors[index];} // return a reference to the "indexth" floor
    const Elevator& getElevator(int index) const{return *Elevators[index];} // return a reference to the "indexth" elevator

    friend ostream& operator<<(ostream&, const Building&);
    
    Building& step(int);

    void getDifferentInts(int, int&, int&);
    ~Building();
    
private:
    
    int SimulationTime;
    vector<Floor*> Floors;
    vector<Elevator*> Elevators;
    
};


#endif
