#include<iostream>
using namespace std;
class Time{
    private:
    int hours;
    int minutes;
    int seconds;

    public:
    Time():hours(0),minutes(0),seconds(0){}
    
    Time(int h,int m,int s):hours(h),minutes(m),seconds(s){}

    void display(){
        cout<<hours<<" "<<minutes<<" "<<seconds<<endl;
    }
    Time add(const Time&t){
        Time result;
        result.seconds=seconds+t.seconds;
        result.minutes=minutes+t.minutes+result.seconds/60;
        result.hours=hours+t.hours+result.minutes/60;
        result.seconds%=60;
        result.minutes%=60;
        result.hours%=24;
        return result;
    }
};
int main(){
    Time t1(11,59,24);
    Time t2(3,25,46);
    Time result=t1.add(t2);
    result.display();
    return 0;
}