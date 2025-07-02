/*
Define an exception class called “MyNation” that is thrown when a string is not equal to “jai
hind” or “JAI HIND”. Write a program that implements this exception.
*/
#include <iostream>
#include <exception>
using namespace std;
class MyNation : public exception
{
public:
    const char *what()
    {
        return "Invalid Input";
    }
    string str;
    MyNation(string s) : str(s) {};
};
int main()
{
    string s;
    cout << "Enter the string" << endl;
    getline(cin, s);
    try
    {
        if (s == "JAI HIND" || s == "jai hind")
        {
            cout << "Valid Input" << endl;
        }
        else
        {
            throw MyNation(s);
        }
    }
    catch (MyNation &e)
    {
        cout << e.what() << endl;
    }
    cout << "*************************************************************************************" << endl;
    cout << "Program Prepared and Executed by: Muneef Khan, CSE3(A1), Roll no: 43, Section: A1" << endl;
    cout << "*************************************************************************************" << endl;
    return 0;
}