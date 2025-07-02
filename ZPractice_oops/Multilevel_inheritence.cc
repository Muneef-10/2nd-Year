//Parent have multiple child is hierarchical inheritance
#include<bits/stdc++.h>
using namespace std;
class Person
{
    protected:
    string name;
    public:
    void introduce()
    {
        cout<<"Name is: "<<name<<endl;
    }
};
class Employee: public Person
{
    protected:
    int salary;
    public:
    void monthly_salary()
    {
        cout<<"Salary: "<<salary<<endl;
    }
};
class Manager: public Employee
{
    protected:
    string department;
    public:
    Manager(string name,int salary,string department)
    {
        this->name=name;
        this->salary=salary;
        this->department=department;
    }
    void work()
    {
        cout<<"I am leading the department "<<department<<endl;
    }
};
int main()
{
    Manager A1("Rohit",200,"Electrical");
    A1.work();
    A1.introduce();
    A1.monthly_salary();
    return 0;
}