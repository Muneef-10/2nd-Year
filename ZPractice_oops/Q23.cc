#include<bits/stdc++.h>
using namespace std;
class shape
{
    public:
    virtual void display()=0;
    virtual void erase()=0;
};
class rectangle:public shape
{
    public:
    void display()
    {
        cout<<"Rectangle draw"<<endl;
    }
    void erase()
    {
        cout<<"Rectangle erase"<<endl;
    }
};
class circle: public shape
{
    public:
    void display()
    {
        cout<<"Circle draw"<<endl;
    }
    void erase()
    {
        cout<<"Circle erase"<<endl;
    }
};
int main()
{
    shape *sp;
    circle cr;
    rectangle rt;
    sp=&cr;
    sp->display();
    sp->erase();
    sp=&rt;
    sp->display();
    sp->erase();
    return 0;
}