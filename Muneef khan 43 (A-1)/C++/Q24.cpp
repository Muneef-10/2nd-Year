/*
Solve the following problem by using runtime polymorphism:
Following tables outlines the major credit cards you might want to validate, along with their allowed
prefixes and lengths. Major Credit Cards, Their Prefixes, and Lengths
Card Type Prefixes Length
MasterCard 51-55 16
Visa 4 13,16
American
Express 34,37 15
Sample Well-Formed Credit Card Numbers
Card Type Sample Number
MasterCard 5500 0000 0000 0004
Visa 4111 1111 1111 1111
American Express 3400 0000 0000 009
*/
#include <iostream>
using namespace std;
class Card
{
public:
    string s;
    Card(string s) : s(s) {}
    virtual void check() {};
};
class Mastercard : public Card
{
public:
    Mastercard(string s) : Card(s) {}
    void check()
    {
        if (s.length() == 16 && s[0] == '5' && s[1] == '1' || s[1] == '5')
        {
            cout << "valid Master card" << endl;
        }
        else
        {
            cout << "Not a valid Master card" << endl;
        }
    }
};
class AmericanExpress : public Card
{
public:
    AmericanExpress(string s) : Card(s) {}
    void check()
    {
        if (s.length() == 15 && s[0] == '3' && s[1] == '4' || s[1] == '7')
        {
            cout << "valid AmericanExpress card" << endl;
        }
        else
        {
            cout << "Not a valid AmericanExpress card" << endl;
        }
    }
};
class Visacard : public Card
{
public:
    Visacard(string s) : Card(s) {}
    void check()
    {
        if (s.length() == 16 || s.length() == 13 && s[0] == '4')
        {
            cout << "valid Visa card" << endl;
        }
        else
        {
            cout << "Not a valid Visa card" << endl;
        }
    }
};
int main()
{
    int ch;
    string CardNo;
    Card *cd;
    int choice;
    do
    {
        cout << "Enter the card number: ";
        cin >> CardNo;
        cout << "Press :\n[1] to check whether the card is Master card\n[2] to check whether the card is Visa card \n[3] to check whether the card is American express\n[4] to exit "<<endl; 
        cin >> choice;
        switch (choice)
        {
        case 1:
            cd = new Mastercard(CardNo);
            cd->check();
            break;
        case 2:
            cd = new Visacard(CardNo);
            cd->check();
            break;
        case 3:
            cd = new AmericanExpress(CardNo);
            cd->check();
            break;
        case 4:
            cout << "Exiting... " << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
        cout << "Do you want to continue y/n[1/0]: ";
        cin >> ch;
    } while (ch != 0);
    cout << "*************************************************************************************" << endl;
    cout << "Program Prepared and Executed by: Muneef Khan, CSE3(A1), Roll no: 43, Section: A1" << endl;
    cout << "*************************************************************************************" << endl;
    return 0;
}
