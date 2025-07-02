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
};


int main()
{
    Cricketer c1("Virat Kohli",25000,55.2);
    Cricketer c2("Rohti Sharma",18000,47.8);

    cout<<c1.name<<" "<<c1.runs<<" "<<c1.avg<<endl;
    cout<<c2.name<<" "<<c2.runs<<" "<<c2.avg<<endl;

    return 0;
}