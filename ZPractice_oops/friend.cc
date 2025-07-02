#include<iostream>
using namespace std;
class demo
{
    private:
    int a,b;
    public:
    void getdata();
    friend int sum(demo);
};
void demo::getdata()
{
    cout<<"Enter 2 no.s: ";
    cin>>a>>b;
}
int sum(demo d)
{
    return d.a+d.b;
}
int main()
{
    demo d1;
    d1.getdata();
    cout<<sum(d1);

    return 0;
}