/*Define an exception class called InvalidAgeException that accept user’s age and if the age 
is less than 18 then throw an exception with suitable error message and catch it by displaying 
that message.*/

#include<bits/stdc++.h>
using namespace std;
class InvalidAgeException: public exception
{
    public:
    const char *what()
    {
        return "You are under age\n";
    }
    int age;
    InvalidAgeException(int age)
    {
        this->age=age;
    }
};
int main()
{
    int age;
    cout<<"Enter age: ";
    cin>>age;
    try
    {
        if(age<18)
            throw InvalidAgeException(age);
        else
            cout<<"Age is: "<<age<<endl;

    }
    catch(InvalidAgeException &e)
    {
        cout<<e.what()<<endl;
    }

    return 0;
}