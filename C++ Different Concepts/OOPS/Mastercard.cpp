#include <iostream>
#include <string>
using namespace std;

class CreditCard
{
protected:
    string cardNumber;

public:
    CreditCard(string number)
    {
        cardNumber = number;
    }

    virtual bool validate() const
    {
        return true;
    }
};

class MasterCard : public CreditCard
{
public:
    MasterCard(string number) : CreditCard(number) {}

    bool validate() const
    {
        if (cardNumber.length() != 16)
            return false;

        int prefix = stoi(cardNumber.substr(0, 2)); 

        if(prefix >= 51 && prefix <= 55)
        return true;
        else
        return false;    
    }
};

class Visa : public CreditCard
// class Visa : public CreditCard
{
public:
    Visa(string number) : CreditCard(number) {}

    bool validate() const
    {
        int length = cardNumber.length();

        if((length == 13 || length == 16) && cardNumber[0] == '4')
        return true;
        else
        return false;
    }
};

class AmericanExpress : public CreditCard
{
public:
    AmericanExpress(string number) : CreditCard(number) {}

    bool validate() const
    {
        if (cardNumber.length() != 15)
            return false;

        int prefix = stoi(cardNumber.substr(0, 2)); 

        if(prefix == 34 || prefix == 37)
        return true;
        else
        return false;    
    }
};

int main()
{
    string x;
    cout<<"Enter number: ";
    getline(cin,x);
    MasterCard masterCard(x);
    // 5500000000000004
    Visa visaCard(x);
    // 4111111111111111
    AmericanExpress amexCard(x);
    // 340000000000009

    cout << "MasterCard valid: ";
    if(masterCard.validate())
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    cout << "Visa valid: ";
    if(visaCard.validate())
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    cout << "American Express valid: ";
    if(amexCard.validate())
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}