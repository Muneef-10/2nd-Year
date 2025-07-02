#include<iostream>
using namespace std;
class Ride
{
    public:
    virtual void calculateFare(int x,int charges)
    {
        x=x*charges;
    }
};
class StandardRide : public Ride
{
    public:
    void calculatefare(int x,int charges)
    {
        x=x*charges;
        cout<<"Charges: "<<x<<endl;
    }
    
};
class PremiumRide : public Ride
{
    public:
};
class CarpoolRide : public Ride
{
    public:
};
int main()
{
    cout<<"**********CAHRGES**********"<<endl;
    cout<<"For Standard 15rupee per KM"<<endl;
    cout<<"For Premiun 20rupee per KM"<<endl;
    cout<<"For Carpool 25rupee per KM"<<endl;
    int x;
    cout<<"Enter distance in KM: ";
    cin>>x;
    Ride *ref;
    StandardRide obj1;
    PremiumRide obj2;
    CarpoolRide obj3;
    ref=&obj1;
    ref->calculateFare(x,15);
    return 0;
}