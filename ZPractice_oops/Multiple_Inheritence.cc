#include<bits/stdc++.h>
using namespace std;
class Engineer
{
    public:
    string specializations;
    void work()
    {
        cout<<"I have specializations in "<<specializations<<endl;
    }
    Engineer()
    {
        cout<<"Hello Engineer"<<endl;
    }
};
class Youtuber
{
    public:
    int subscribers;

    Youtuber()
    {
        cout<<"Hello Youtuber"<<endl;
    }
    void contentcreater()
    {
        cout<<"I have a subscriber base of: "<<subscribers<<endl;

    }
};
class CodeTeacher: public Engineer,public Youtuber
{
    public:
    string name;
    CodeTeacher()
    {
        cout<<"Hello CodeTeacher"<<endl;
    }
    CodeTeacher(string name,int subscribers,string specializations)
    {
        this->name=name;
        this->specializations=specializations;
        this->subscribers=subscribers;
    }
    void display()
    {
        cout<<"Name: "<<name<<endl;
        work();
        contentcreater();
    }
};
int main()
{
    CodeTeacher A;
    CodeTeacher A1("Rohit",2000,"CSE");
    A1.display();
    return 0;
}