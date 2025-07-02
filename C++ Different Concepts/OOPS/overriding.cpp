//Is concept ko function overriding bola jata hai

#include<iostream>
#include<vector>
using namespace std;
class Scooty
{
public:
    int topspeed;
    float mileage;
    virtual void sound() // virtual likhne pr fir pointer scooty ka hi kio na ho pr NEW BIKE ko vo point kr raha hai to waha Dhroom Dhroom hi aaega(means vo bike ko hi point krega)
    {
        cout<<"Vroom Vroom"<<endl;
    }
private:
    int bootSpace;
};
class Bike : public Scooty
{
public:
    int gears;
    void sound()
    {
        cout<<"Dhroom Dhroom"<<endl;
    }
};
class SuperBike : public Scooty
{
public:
    void sound()
    {
        cout<<"Zroom Zroom"<<endl;
    }
};
int main()
{
    // Bike* b = new Bike();  // Object pointer
    // b->sound();  OUTPUT:- dhroom dhroom
    Scooty* b = new Bike();
    b->sound();  // agr scooty se sound hi hta di tab waha error aa jaega jab virtual na likha ho
    // SuperBike* c = new SuperBike();
    // c->sound();
    Scooty* c = new SuperBike();
    c->sound();
    vector<Scooty*> v;

    return 0;
}