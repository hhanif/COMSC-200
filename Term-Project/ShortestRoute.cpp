// Term Project
// Programmer: Haris Hanif
// Editor(s) used: Sublime Text 2
// Compiler(s) used: G++

#include <iostream>
using std::cout;
using std::endl;
using std::ios;

#include <ostream>
using std::ostream;

#include <string>
using std::string;

#include <set>
using std::set;

#include <vector>
using std::vector;

#include <cassert>

class Route;
class Leg;
class ShortestRoute;


class Leg
{
private:
	const string StartCity;
	const string EndCity;
	const double distance;
public:
	Leg(const string StartLocation,const string EndLocation, const double miles):StartCity(StartLocation),EndCity(EndLocation), distance(miles){};
    double getDistance() const {return distance;}
    friend class Route;
    friend class ShortestRoute;
    void operator=(const Leg&){assert(false);}
    friend ostream& operator<<(ostream&, const Leg&);
    friend ostream& operator<<(ostream&, const Route&);
    friend int CityOrder(const Leg&, const Leg&);

};
class Route
{
private:
	const int count;
    const Leg** const leg;
	const double TotalDistance;
public:
	Route(const Leg&);
	Route(const Route&, const Leg&);
    Route(const Route&);
    ~Route();
	void friend outputRoute(ostream&, const Route&);
    bool isGreaterThan(const Route&) const;
    bool operator<(const Route&) const;
    friend class ShortestRoute;
    friend ostream& operator<<(ostream& out, const Route& route);
    void operator=(const Route&){ assert(false); }
    double getTotalDistance() const {return TotalDistance;}
    friend int CityOrder(const Leg&, const Leg&);
};

class ShortestRoute
{
public:
    static vector<Leg> Legs;

    static void addLeg(Leg& Leg)
    {
        Legs.push_back(Leg);
    }

    static const Route getAnyRoute(const string from, const string to)
    {
        for(int i =0; i < Legs.size() ;i++){
            if(Legs[i].EndCity.compare(to) == 0){
                if(Legs[i].StartCity.compare(from) == 0){
                    return Route(Legs[i]);
                }
                else {
                    return Route(getAnyRoute(from, Legs[i].StartCity), Legs[i]);
                }
            }
        }		
    }

    static const Route getShortestRoute(const string from, const string to)
    {
        
        set<Route> routes;
        
        for(int i =0; i < Legs.size(); i++)
        {
            if(Legs[i].EndCity.compare(to) == 0)
            {
                if(Legs[i].StartCity.compare(from)==0)
                {
                    routes.insert(Route(Legs[i]));
                }
                else
                {
                    routes.insert(Route(getShortestRoute(from, Legs[i].StartCity), Legs[i]));
                }
            }
        }
        set<Route>::iterator it = routes.begin();
        return *it;
        
    }
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
        throw "The Starting city doesn't match the ending city\n";
    }
    
	for(int i = 0; i< count-1; i++)
		leg[i] = route.leg[i];
    
	leg[route.count]=&AddLeg;
}

Route::Route(const Route& route):count(route.count), leg(new const Leg * [count]), TotalDistance(route.getTotalDistance())
{
    for(int i = 0; i < route.count; i++)
    {
        leg[i] = route.leg[i];
    }
}

Route::~Route()
{
    delete[] leg;
}

bool Route::isGreaterThan(const Route& R) const
{
    if(this->TotalDistance > R.TotalDistance)
        
        return true;
    
    else
        
        return false;
}

bool Route::operator<(const Route& R) const
{
    if (this->isGreaterThan(R))
        return false;
    else
        return true;
}


ostream& operator<<(ostream& Output, const Leg& drive)
{
    Output << drive.StartCity;
    Output << " -> ";
    Output << drive.EndCity;
    Output << "is a total of  ";
    Output << drive.distance;
    Output << " miles.";
    Output << endl;
    return Output;
}

ostream& operator<<(ostream& print, const Route& trip)
{
    print << trip.leg[0]->StartCity;
    
    for(int i = 1; i<trip.count; i++)
    {
        print << " to ";
        print << trip.leg[i]->StartCity;
    }
    
    print << " to ";
    print<< trip.leg[trip.count-1]->EndCity;
    
    print << " is a total of ";
    print << trip.TotalDistance;
    print << " miles ";
    print << endl;
    return print;
}

int CityOrder(const Leg& leg1, const Leg& leg2)
{
    return (leg1.EndCity.compare(leg2.StartCity) == 0);
}

vector<Leg> ShortestRoute::Legs;

int main()
{
    // print my name and this assignment's title
    cout << "Term Project \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Sublime Text 2\n";
    cout << "Compiler(s) used: G++\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    
    Leg a("San Francisco", "San Jose", 55.0);
    Leg b("San Jose", "Pleasanton", 30.4);
    Leg c("San Jose", "Stockton",60.2);
    Leg d("Pleasanton", "Stockton", 48.2);
    Leg e("Pleasanton", "Salida", 50.2);
    Leg f("Stockton", "Elko",470.2);
    Leg g("Stockton", "Fallon",244.5);
    Leg h("Salida", "Elko",259.5);
    Leg i("Salida","Fallon",485.0);
    Leg j("Elko","Salt Lake City",230.2);
    Leg k("Elko","Provo",272.3);
    Leg l("Fallon","Provo",523.2);
    Leg m("Fallon","Salt Lake City",482.2);
    Leg n("Provo","Rawlins",308.2);
    Leg o("Provo","Scottsbluff",554.3);
    Leg p("Salt Lake City","Provo",57.3);
    Leg q("Salt Lake City","Rawlins",291.2);
    Leg r("Salt Lake City","Scottsbluff",537.2);
    Leg s("Rawlins","Licoln",322.3);
    Leg t("Rawlins","Minneapolis",954.2);
    Leg u("Scottsbluff","Licoln",400.4);
    Leg v("Scottsbluff","Minneapolis",710.2);
    Leg w("Licoln","Chicago",520.1);
    Leg x("Licoln","Indianapolis",636.6);
    Leg y("Minneapolis","Chicago",409.5);
    Leg z("Minneapolis","Indianapolis",592.8);
    Leg AA("Indianapolis","Columbus",176.3);
    Leg BB("Indianapolis","Lexington",189.3);
    Leg CC("Chicago","Columbus",356.5);
    Leg DD("Chicago","Lexington",373.2);
    Leg EE("Columbus","Pittsburg",185.5);
    Leg FF("Columbus","Detroit",207.3);
    Leg GG("Lexington","Pittsburg",371.3);
    Leg HH("Lexington","Detroit",344.4);
    Leg II("Pittsburg","Philadelphia",304.9);
    Leg JJ("Pittsburg","New York",374.5);
    Leg KK("Detroit","Philadelphia",584.3);
    Leg LL("Detroit","Rochester",617.3);
    Leg MM("Philadelphia","Rochester",96.7);
    Leg NN("Rochester", "New York",20);
    Leg OO("San Francisco", "New York", 21000);

    ShortestRoute::addLeg(a);
    ShortestRoute::addLeg(b);
    ShortestRoute::addLeg(c);
    ShortestRoute::addLeg(d);
    ShortestRoute::addLeg(e);
    ShortestRoute::addLeg(f);
    ShortestRoute::addLeg(g);
    ShortestRoute::addLeg(h);
    ShortestRoute::addLeg(i);
    ShortestRoute::addLeg(j);
    ShortestRoute::addLeg(k);
    ShortestRoute::addLeg(l);
    ShortestRoute::addLeg(m);
    ShortestRoute::addLeg(n);
    ShortestRoute::addLeg(o);
    ShortestRoute::addLeg(p);
    ShortestRoute::addLeg(q);
    ShortestRoute::addLeg(r);
    ShortestRoute::addLeg(s);
    ShortestRoute::addLeg(t);
    ShortestRoute::addLeg(u);
    ShortestRoute::addLeg(v);
    ShortestRoute::addLeg(w);
    ShortestRoute::addLeg(x);
    ShortestRoute::addLeg(y);
    ShortestRoute::addLeg(z);
    ShortestRoute::addLeg(AA);
    ShortestRoute::addLeg(BB);
    ShortestRoute::addLeg(CC);
    ShortestRoute::addLeg(DD);
    ShortestRoute::addLeg(EE);
    ShortestRoute::addLeg(FF);
    ShortestRoute::addLeg(GG);
    ShortestRoute::addLeg(HH);
    ShortestRoute::addLeg(II);
    ShortestRoute::addLeg(JJ);
    ShortestRoute::addLeg(KK);
    ShortestRoute::addLeg(LL);
    ShortestRoute::addLeg(MM);
    ShortestRoute::addLeg(NN);
    ShortestRoute::addLeg(OO);

    
        cout << "Any route from San Francisco to New York:";
        cout << endl;
        cout << ShortestRoute::getAnyRoute("San Francisco", "New York");
        cout << endl;
        cout << "Shortest route from San Francisco to New York:";
        cout << endl;
        cout << ShortestRoute::getShortestRoute("San Francisco", "New York");
    
    return 0;
}
