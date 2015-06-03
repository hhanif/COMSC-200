// Lab 8B, Elevator Simulation Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: G++

#ifndef Rider_h
#define Rider_h
class Floor;
class Rider
{
public:
    Rider(const Floor& f):Destination(&f), IdentificationNumber(Track)
    {
        ++Track;
    }
    
	bool operator == (const Rider&) const;
	bool operator < (const Rider&) const;
    
    const Floor& getDestination() const
    {
        return *Destination;
    }

private:
    const int IdentificationNumber;
    const Floor* const Destination;
    static int Track;

};


#endif
