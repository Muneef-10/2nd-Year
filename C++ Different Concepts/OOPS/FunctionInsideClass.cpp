#include<iostream>
using namespace std;
class Cricketer
{
    public:
    string name;
    int runs;
    float avg;
    Cricketer(string name,int runs, float avg)
    {
        this->name = name;
        this->runs = runs;
        this->avg = avg;
    }

    void print(int a)//You can also receive a parameter in this fn.
    {
        //cout<<name<<" "<<runs<<" "<<avg<<endl;  both have same use HERE
        cout<<this->name<<" "<<this->runs<<" "<<this->avg<<endl;
        cout<<a<<endl;
    }
};

int main()
{
    Cricketer c1("Virat Kohli",25000,55.2);
    Cricketer c2("Rohti Sharma",18000,47.8);

    //c1.name = "Sachin";
    c1.print(1);
    c2.print(4);

    return 0;
}