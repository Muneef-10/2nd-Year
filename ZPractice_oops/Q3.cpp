/* An electricity board charges the following rates to domestic users to discourage large consumption of energy. 
For the first 100 units: - 60 P per unit
For the next 200 units: -80 P per unit 
Beyond 300 units: -90 P per unit
All users are charged a minimum of Rs 50 if the total amount is more than Rs 300 then an additional surcharge of 15% is added. 
Implement a C++ program to read the names of users and number of units consumed and display the charges with names */

#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of users: ";
    cin>>n;
    string name[n];
    float unit[n],bill[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter name of user "<<i+1<<": ";
        cin>>name[i];
        cout<<"Enter units of user "<<i+1<<": ";
        cin>>unit[i];
        if(unit[i]<=100) bill[i]=unit[i]*0.6;
        else if(unit[i]>100 && unit[i]<=300) bill[i]=60+((unit[i]-100)*0.8);
        else bill[i]=220+((unit[i]-300)*0.9);
        
        if(bill[i]<50) bill[i]=50;
        if(bill[i]>300)  bill[i]=bill[i]+(0.15*bill[i]);
    }
    for (int i = 0; i < n; i++)
    {

        cout<<"Name: "<<name[i]<<"\nAmount: "<<bill[i]<<endl<<endl;
    }
    
    
    return 0;
}