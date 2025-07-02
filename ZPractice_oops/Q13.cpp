#include<iostream>
#include<iomanip>
using namespace std;
class Time
{
    private:
        int hours;
        int min;
        int sec;
    public:
        Time()
        {
            hours=0;
            min=0;
            sec=0;
        }
        Time(int h,int m,int s)
        {
            hours=h;
            min=m;
            sec=s;
        }
        void calculate()
        {
            if(sec>=60)
            {
                min=min+sec/60;
                sec=sec%60;
            }
            if(min>=60)
            {
                hours=hours+min/60;
                min=min%60;
            }  
        }
        Time operator+(const Time &t)
        {
            Time result;
            result.hours=this->hours+t.hours;
            result.min=this->min+t.min;
            result.sec=this->sec+t.sec;
            result.calculate();
            return result;
        }
        void display()
        {
            cout<<setw(2)<<setfill('0')<<hours<<":"<<setw(2)<<setfill('0')<<min<<":"<<setw(2)<<setfill('0')<<sec<<endl;
        }
};
int main()
{
    Time t1(2,45,30);
    Time t2(1,20,40);
    Time t3=t1+t2;
    t3.display();
    return 0;
}