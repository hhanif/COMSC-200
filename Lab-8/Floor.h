// Lab 8B, Elevator Simulation Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: G++

#ifndef FLOOR_H
#define FLOOR_H

class Floor{
public:
	Floor(const int FloorLocation):FloorLocation(FloorLocation){}
	int getLocation() const
    {
        return FloorLocation;
    }
private:
	const int FloorLocation;
    
};


#endif
