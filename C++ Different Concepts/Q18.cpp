/* Program to demonstrates all the possible uses of the scope resolution operator in a single program:*/
#include<iostream>
using namespace std;
class Base
{
    public:
    int w;
};
class Derived1 : public Base
{
    public:
    int x;
};
class Derived2 :public Base
{
    public:
    int y;
};
class Derived3 :public Derived1, public Derived2
{
    public:
    int z;
};
int main()
{
    Derived3 A;
    A.Derived1::w=10;
    A.Derived2::w=20;
    A.x=30;
    A.y=40;
    A.z=50;

    cout<<"W from class Derived1 = "<<A.Derived1::w<<endl;
    cout<<"W from class Derived2 = "<<A.Derived2::w<<endl;
    cout<<"x = "<<A.x<<endl;
    cout<<"y = "<<A.y<<endl;
    cout<<"z = "<<A.z<<endl;
    cout<<endl<<"*************************************************************"<<endl;
    cout<<"Program Prepared & Executes by:Muneef Khan, Class Roll no.: 43"<<endl;
    cout<<"*************************************************************"<<endl;
    return 0;
}
