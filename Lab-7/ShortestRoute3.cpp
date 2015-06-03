// Lab 7B, Shortest Route Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: G++

#include <iostream>
using std::cout;
using std::endl;
using std::ios;
using std::ostream;

#include <string>
using std::string;

class Route;

class Leg
{
private:
	const string StartCity;
	const string EndCity;
	const double distance;
public:
	Leg(const string StartLocation,const string EndLocation, const double miles):StartCity(StartLocation),EndCity(EndLocation), distance(miles){};
    friend class Route;
    void friend outputLeg(ostream&, const Leg&);
    void friend outputRoute(ostream&, const Route&);
};
class Route
{
private:
	const int count;
    const Leg** const leg;
	const double TotalDistance;
public:
	Route(const Leg&);
    Route(const Route&);
	Route(const Route&, const Leg&);
	~Route(){delete[] leg;}
	void friend outputRoute(ostream&, const Route&);
    bool isGreaterThan(const Route&) const;
    
};
Route::Route(const Leg& SimpleLeg):leg(new const Leg*[1]), count(1), TotalDistance(SimpleLeg.distance)
{
	leg[0]=&SimpleLeg;
}

Route::Route(const Route& route, const Leg& AddLeg):leg(new const Leg*[route.count+1]), count(route.count+1), TotalDistance(route.TotalDistance + AddLeg.distance)
{
    
    if(route.leg[count-2]->EndCity != AddLeg.StartCity)
    {
        delete [] leg;
        throw "The Starting city doesn't match the last end city\n";
    }
    
	for(int i = 0; i< count-1; i++)
		leg[i] = route.leg[i];
    
	leg[route.count]=&AddLeg;
}

Route::Route(const Route& copy):leg(new const Leg*[count]), count(copy.count), TotalDistance(copy.TotalDistance)
{
	for(int i=0; i<copy.count+1; i++)
		leg[i]=copy.leg[i];
}

void outputLeg(ostream&, const Leg&);
void outputRoute(ostream&, const Route&);


int main()
{
    // print my name and this assignment's title
    cout << "Lab 7B, Shortest Route Program \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: G++\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    //Create Legs
    const Leg a("San Francisco", "San Jose", 20.0);
    const Leg b("San Jose", "Los Angeles", 340.0);
    const Leg c("Los Angeles", "San Diego", 120.0);
    const Leg d("San Diego", "Seattle", 1255.0);
    const Leg e("Seattle", "Santa Clara", 839.0);
    
    const Route ra(a); // route from San Francisco to San Jose
    const Route rb(ra, b); // route from San Jose to Los Angeles
	const Route rc(rb, c);
	const Route rd(rc, d);
	const Route re(rd, e);
	cout << endl;
    
    try
    {
        Route(Route(Leg("a", "b", 0)), Leg("c", "d", 0));
    }
    catch (const char* ex)
    {
        cout << "ERROR DETECTED: " << ex << endl;
    }
    
    
    outputLeg(cout, a);
    outputLeg(cout, b);
    outputLeg(cout, c);
    outputLeg(cout, d);
    outputLeg(cout, e);
    
    outputRoute(cout, re);
    
    cout << endl;
    
    if(rb.isGreaterThan(ra))
        
		cout << "Route RB is longer than Route RA"<<endl;
    
	else
        
		cout << "Route RA is longer than Route RB"<<endl;
    
	if(rb.isGreaterThan(rc))
        
		cout << "Route RB is longer than Route RC"<<endl;
    
	else
        
		cout << "Route RC is longer than Route RB"<<endl;
    
	if(rb.isGreaterThan(rd))
        
		cout << "Route RB is longer than Route RD"<<endl;
    
	else
        
		cout << "Route RD is longer than Route RB"<<endl;
    
    
    {
		cout << "Test copy constructor" <<endl;
		Route rCopy = ra;
		outputRoute(cout, rCopy);
		cout<<endl;
	}
	cout<<"Test Original" <<endl;
	outputRoute(cout, ra);
	cout << endl;
    
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

void outputRoute(ostream& print, const Route& trip)
{
	print<< trip.leg[0]->StartCity;
    
	for(int i = 1; i<trip.count; i++)
		print << " to " << trip.leg[i]->StartCity;
    
	print << " to " << trip.leg[trip.count-1]->EndCity;
    
	print << " is a total of " << trip.TotalDistance << " miles " << endl;
}

bool Route::isGreaterThan(const Route& r) const
{
	if(this->TotalDistance > r.TotalDistance)
        
		return true;
    
	else
        
        return false;
    
}
