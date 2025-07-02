#include<iostream>
using namespace std;
class Employee
{
    public:
    string name;
    int salary;

    void p()
    {
        cout<<"Name of employee is "<<this->name<<" and his salary is "<<this->salary<<" thousand dOllars.";
    }
}mk;
int main()
{
   // Employee mk;
    mk.name="Muneef";
    mk.salary=100;
    mk.p();
    // cout<<mk.name<<endl<<mk.salary;
}