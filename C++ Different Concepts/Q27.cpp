/*Define an exception class called InvalidAgeException that accept user’s age and if the age
is less than 18 then throw an exception with suitable error message and catch it by displaying
that message.*/
#include <iostream>
#include <exception>
using namespace std;
class InvalidAgeException : public exception
{
public:
    const char *what()
    {
        return "You are under age";
    }
    int age;
    InvalidAgeException(int n) : age(n) {}
};
int main()
{
    int age;
    cout << "Enter the age: ";
    cin >> age;
    try
    {
        if (age < 18)
        {
            throw InvalidAgeException(age);
        }
        else
        {
            cout << age << endl;
        }
    }
    catch (InvalidAgeException &ob)
    {
        cout << ob.what() << endl;
    }
    cout << "*************************************************************************************" << endl;
    cout << "Program Prepared and Executed by: Muneef Khan, CSE3(A1), Roll no: 43, Section: A1" << endl;
    cout << "*************************************************************************************" << endl;
    return 0;
}
