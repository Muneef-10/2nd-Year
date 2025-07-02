/* Develop an abstract class Ride with a pure virtual function calculateFare(). Derive classes
like StandardRide, PremiumRide, and CarpoolRide, each implementing calculateFare() based on
unique pricing models. */
#include <iostream>
using namespace std;
class Ride
{
public:
    int d;
    Ride(int d) : d(d) {};
    virtual void compute() = 0;
};
class StandardRide : public Ride
{
public:
    StandardRide(int d) : Ride(d) {}
    void compute()
    {
        int amt;
        amt = d * 11;
        cout << "Price: " << amt << endl;
    }
};
class PremiumRide : public Ride
{
public:
    PremiumRide(int d) : Ride(d) {}
    void compute()
    {
        int amt;
        amt = d * 12;
        cout << "Price: " << amt << endl;
    }
};
class CarpoolRide : public Ride
{
public:
    CarpoolRide(int d) : Ride(d) {}
    void compute()
    {
        int amt;
        amt = d * 15;
        cout << "Price: " << amt << endl;
    }
};
int main()
{
    int ch;
    int d;
    int choice;
    Ride *ride;
    do
    {
        cout << "Enter the distance : ";
        cin >> d;
        cout << "Price chart :\n Standard ride: Rs 11/km\n Premium ride: Rs 12/km\n Carpoolride: Rs 15/km\nPress :\n[1] To calculate Price of Standard ride\n[2] To calculate Price of Premium ride \n[3] To calculate Price of Carpool\n[4] to exit "<<endl; 
            cout
             << "Enter the choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            ride = new StandardRide(d);
            ride->compute();
            break;
        case 2:
            ride = new PremiumRide(d);
            ride->compute();
            break;
        case 3:
            ride = new CarpoolRide(d);
            ride->compute();
            break;
        case 4:
            cout << "Exiting... " << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
        cout << "Do you want to continue y/n[1/0]: ";
        cin >> ch;
    }
    while (ch != 0);
    cout << "*************************************************************************************" << endl; 
        cout<< "Program Prepared and Executed by: Muneef Khan, CSE3(A1), Roll no: 43, Section: A1 " << endl; 
        cout<< "*************************************************************************************" << endl; 
    return 0;
}