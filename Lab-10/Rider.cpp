// Lab 10B, Elevator Simulation Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: G++

#include "Rider.h"
int Rider::Track = 0;

bool Rider::operator==(const Rider& r) const
{
    bool result = true;
    if (IdentificationNumber != r.IdentificationNumber)
        result = false;
    
    return result;
}

bool Rider::operator<(const Rider& r) const
{
    bool result = false;
    if (IdentificationNumber < r.IdentificationNumber)
        result = true;
    
    return result;
}

const Rider& Rider::operator=(const Rider &r)
{
    if (&r!=this)
    {
        const_cast<int&>(IdentificationNumber) = r.IdentificationNumber;
        const_cast<const Floor*&>(Destination) = r.Destination;
    }
    return *this;
}
