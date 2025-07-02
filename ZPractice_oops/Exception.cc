#include<bits/stdc++.h>
using namespace std;
class Customer
{
    string name;
    int balance,accno;
    public:
    Customer(string name,int balance,int accno)
    {
        this->name=name;
        this->balance=balance;
        this->accno=accno;
    }
    void deposit(int amount)
    {
        if(amount>0)
        {
            balance=balance+amount;
            cout<<amount<<" is credited successfully"<<balance<<endl;
        }
        else
        {
            throw "Amount should be greater than 0";
        }
    }
    void withdraw(int amount)
    {
        if(amount>0 && amount <=balance)
        {
            balance=balance-amount;
            cout<<amount<<" is debited successfully"<<balance<<endl;
        }
        else if(amount<0)
        {
            throw "Amount should be greater than 0";
        }
        else
        {
            throw "Your balance is low";
        }
    }
};
int main()
{
    Customer c("Rohit",5000,1254);

    try
    {
        c.deposit(100);
        c.withdraw(6000);
        c.deposit(100);
    }
    catch(const char *e)
    {
        cout<<"Exception occured: "<<e<<endl;
    }
    return 0;
}