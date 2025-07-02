/* Develop an abstract class Ride with a pure virtual function calculateFare(). Derive classes 
like StandardRide, PremiumRide, and CarpoolRide, each implementing calculateFare() based on 
unique pricing models.*/
#include<bits/stdc++.h>
using namespace std;
class Ride
{
    public:
    int distance;
    virtual void calculatefare()=0;
};
class StandardRide:public Ride
{
    public:
    StandardRide(int distance)
    {
        this->distance=distance;
    }
    void calculatefare()
    {
        int amt;
        amt=distance*11;
        cout<<"Standard ride fair: "<<amt<<endl;
    }    
};
class PremiumRide:public Ride
{
    public:
    PremiumRide(int distance)
    {
        this->distance=distance;
    }
    void calculatefare()
    {
        int amt;
        amt=distance*12;
        cout<<"Premium ride fair: "<<amt<<endl;
    }
};
class CarpoolRide:public Ride
{
    public:
    CarpoolRide(int distance)
    {
        this->distance=distance;
    }
    void calculatefare()
    {
        int amt;
        amt=distance*15;
        cout<<"Carpool ride fair: "<<amt<<endl;
    }
};
int main()
{
    int choice;
    Ride *r;
    int distance;
    do
    {
        cout<<"Press [1] to Standard ride: "<<endl;
        cout<<"Press [2] to Premium ride: "<<endl;
        cout<<"Press [3] to Carpool ride: "<<endl;
        cout<<"Press [0] to exit: "<<endl;
        cin>>choice;
        cout<<"Enter distance: ";
        cin>>distance;
        switch (choice)
        {
        case 0:
            cout<<"Exit.."<<endl;
            break;
        case 1:
            r=new StandardRide(distance);
            r->calculatefare();
            break;
        case 2:
            r=new PremiumRide(distance);
            r->calculatefare();
            break;
        case 3:
            r=new CarpoolRide(distance);
            r->calculatefare();
            break;
        
        default:
            break;
        }
    } while (choice!=0);
    
    return 0;
}