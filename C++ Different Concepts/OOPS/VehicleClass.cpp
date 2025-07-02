#include<iostream>
using namespace std;
class Vehicle  // parent class
{
public:
    int topspeed;
    float mileage;
    string fuel;
};
class Car : public Vehicle  // Bike is child class / derived class
{
public:
    bool sunroof;
};
class Bike : public Vehicle  // Bike is child class / derived class
{
public:
        
};
class Truck : public Vehicle  // Bike is child class / derived class
{
public:
    
};

int main()
{
    Bike b1;
    b1.topspeed = 180;
    b1.mileage = 12.5;
    
}