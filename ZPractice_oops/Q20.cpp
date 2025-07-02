/*Develop a simulation for an autonomous vehicle. Create a base class Vehicle with properties 
like speed and fuelLevel. Then, derive LandVehicle and FlyingVehicle, where each has unique 
attributes like wheelCount and altitude. Create a FlyingCar class that inherits from both 
LandVehicle and FlyingVehicle, demonstrating how a flying car would combine the capabilities 
of land and aerial vehicles.*/

#include<bits/stdc++.h>
using namespace std;
class Vehicle
{
    protected:
    int speed;
    int fuellevel;
    public:

    void displayv()
    {
        cout<<"Speed: "<<speed<<endl;
        cout<<"Fuellevel: "<<fuellevel<<endl;
    }
};
class LandVehicle: public virtual Vehicle
{
    protected:
    int wheelCount;
    public:

    void displayl()
    {
        cout<<"Land vehicle"<<endl;
        displayv();
        cout<<"WheelCount: "<<wheelCount<<endl;
    }
};
class FlyingVehicle: public virtual Vehicle
{
    protected:
    int altitude;
    public:

    void displayf()
    {
        cout<<"Flying Vehicle"<<endl;
        displayv();
        cout<<"Altitude: "<<altitude<<endl;
    }
};
class FlyingCar: public LandVehicle,public FlyingVehicle
{
    public:
    FlyingCar(int speed,int fuellevel,int wheelCount,int altitude)
    {
        // Vehicle(speed,fuellevel),LandVehicle(speed, fuellevel, wheelcount),FlyingVehicle(speed, fuellevel, altitude)
        this->speed=speed;
        this->wheelCount=wheelCount;
        this->fuellevel=fuellevel;
        this->altitude=altitude;
    }
    void display()
    {
        displayf();
        displayl();
    }

};
int main()
{
    FlyingCar f(58,30,54,55);
    f.display();
    return 0;
}