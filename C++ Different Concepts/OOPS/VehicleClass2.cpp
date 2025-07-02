//Multi level inheritance

#include<iostream>
using namespace std;
class Vehicle  // parent class
{
public:
    int topspeed;
    float mileage;
    string fuel;
};
class TwoWheeler: public Vehicle 
{
public:

};
class FourWheeler: public Vehicle 
{
public:

};
class Scooty : public TwoWheeler 
{
public:
        
};
class Bike : public TwoWheeler  
{
public:
    
};

int main()
{
    Bike b1;
    b1.topspeed = 180;
    b1.mileage = 12.5;
    
}