#include<bits/stdc++.h>
using namespace std;
class Human 
{
    public:
    string name;
    void display()
    {
        cout<<"My name is "<<name<<endl;
    }
};
class Engineer: public virtual Human
{
    public:
    string specializations;
    void work()
    {
        cout<<"I have specializations in "<<specializations<<endl;
    }
};
class Youtuber : public virtual Human
{
    public:
    int subscribers;

    void contentcreater()
    {
        cout<<"I have a subscriber base of: "<<subscribers<<endl;

    }
};
class CodeTeacher:public Youtuber ,public Engineer
{
    public:
    int salary;
    CodeTeacher()
    {

    }
    CodeTeacher(string name,int subscribers,string specializations,int salary)
    {
        this->name=name;
        this->specializations=specializations;
        this->subscribers=subscribers;
        this->salary=salary;
    }
    void show()
    {
        cout<<"Salary is: "<<salary<<endl;
        display();
        contentcreater();
        work();
    }
    
};
int main()
{
    CodeTeacher A1("Rohit",2000,"CSE",150000);
    A1.show();
    return 0;
}