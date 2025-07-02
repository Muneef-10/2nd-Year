/*Q-13) Create a class Time that represents a specific time of day using hours, minutes, and seconds as int data members. Implement the following:
Data Members:
    Three int data members: hours, minutes, and seconds to store the time.
2. Constructors:
    A default constructor that initializes the time to 00:00:00.
    A parameterized constructor that initializes the time to specific values provided by the user.
3. Member Functions:
    A function void display() that displays the time in the format HH:MM:SS.
    Overload the binary + operator as a member function or a friend function to add two Time objects. The result should be returned as a new Time object.
4. Main Function:
    In the main() function, create three Time objects. Initialize the first two objects with specific values using the parameterized constructor.
    Use the overloaded + operator to add the first two Time objects, and store the result in the third Time object.
    Finally, display the time stored in the third object using the display() function.*/


#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
    }

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    void display() const {
        cout << setw(2) << setfill('0') << hours << ":"<< setw(2) << setfill('0') << minutes << ":"<< setw(2) << setfill('0') << seconds << endl;
    }

    Time operator+(const Time& t) const {
        Time result;
        result.hours = this->hours + t.hours;
        result.minutes = this->minutes + t.minutes;
        result.seconds = this->seconds + t.seconds;
        result.normalize();
        return result;
    }
};

int main() {
    Time t1(2, 45, 80); 
    Time t2(1, 20, 40); 

    Time t3 = t1 + t2;

    t1.display();
    t3.display();

    cout<<endl<<"*************************************************************"<<endl;
    cout<<"Program Prepared & Executes by:Muneef Khan, Class Roll no.: 43"<<endl;
    cout<<"*************************************************************"<<endl;
    
    return 0;
}
