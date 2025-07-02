#include<iostream>
using namespace std;
class Point
{
    private:
    int a,b;
    public:
    friend istream& operator>>(istream& input,Point &p)
    {
        input>>p.a;
        input>>p.b;
    }
    friend ostream& operator<<(ostream& output,Point &p)
    {
        output<<"("<<p.a<<","<<p.b<<")";
    }

};
int main()
{
    Point p1;
    cout<<"Enter point: ";
    cin>>p1;
    cout<<"Points are: "<<p1;
    return 0;
}