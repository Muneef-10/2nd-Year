#include<iostream>
using namespace std;
class Car
{
    public:
    string name;
    int price;
    int seat;
    string type;
    Car(string s,int p,int a)
    {
        name=s;
        price=p;
        seat=a;
    }
};

int main()
{
    Car c1("Honda city",1500000,5);
    c1.seat=6;//overwrite apply in output
    c1.type="Sedan";
    cout<<c1.name<<"  "<<c1.price<<"  "<<c1.seat<<"  "<<c1.type<<endl;
    return 0;
}