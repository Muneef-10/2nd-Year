#include<iostream>
using namespace std;
class Car
{
    public:
    string name;
    int price;
    int seat;
    string type;
};
void print(Car c1)
{
    cout<<c1.name<<"  "<<c1.price<<"  "<<c1.seat<<"  "<<c1.type<<endl;
}
void change(Car& c)
//void change(Car& c)  pass by reference
{
    c.name="Audi A8";
}
int main()
{
    Car c1;
    c1.name="Honda city";
    c1.price=1500000;
    c1.seat = 5;
    c1.type = "Sedan";

    print(c1);
    change(c1);// pass by value
    print(c1);

    // Car c2;
    // c2.name="Maruti swift";
    // c2.price=700000;
    // c2.seat = 5;
    // c2.type = "Hatchback";

    // Car c3;
    // c3.name="Toyota Fortuner";
    // c3.price=3600000;
    // c3.seat = 8;
    // c3.type = "SUV";

    // print(c1);
    //print(c2);
    //print(c3);

    return 0;
}