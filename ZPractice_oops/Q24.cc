/* Solve the following problem by using runtime polymorphism: 
Following tables outlines the major credit cards you might want to validate, along with their 
allowed prefixes and lengths. Major Credit Cards, Their Prefixes, and Lengths 
Card Type   Prefixes     Length 
MasterCard   51–55         16 
Visa           4          13,16 
American Express 34,37      15 
Sample Well-Formed Credit Card Numbers 
Card Type Sample Number 
MasterCard 5500 0000 0000 0004 
Visa 4111 1111 1111 1111 
American Express 3400 0000 0000 009*/

#include<bits/stdc++.h>
using namespace std;
class Card
{
    public:
    string s;
    virtual void check(){};
};
class Mastercard:public Card
{
    public:
    Mastercard(string s)
    {
        this->s=s;
    }
    void check()
    {
        if(s.length()==16 && s[0]=='5' && s[1]=='1' || s[1]=='2')
        {
            cout<<"It is a master card"<<endl;
        }
        else cout<<"It is not a master card"<<endl;
    }
};
class Visa : public Card
{
    public:
    Visa(string s)
    {
        this->s=s;
    }
    void check()
    {
        if(s.length()==13 || s.length()==16 && s[0]=='4')
        {
            cout<<"It is a Visa card"<<endl;
        }
        else cout<<"It is not a visa card"<<endl;
    }
};
class American: public Card
{
    public:
    American(string s)
    {
        this->s=s;
    }
    void check()
    {
        if(s.length()==15 && s[0]=='3' && s[1]=='4' || s[1]=='7')
        {
            cout<<"It is a American Express card"<<endl;
        }
        else cout<<"It is not a American Express card"<<endl;
    }
};

int main()
{
    int choice;
    Card *c;
    string cardno;
    do
    {
        cout<<"Enter card number: ";
        cin>>cardno;
        cout<<"Press [1] to check MasterCard"<<endl;
        cout<<"Press [2] to check Visa"<<endl;
        cout<<"Press [3] to check American Express"<<endl;
        cout<<"Press [0] to Exit"<<endl;
        scanf("%d",&choice);
        switch (choice)
        {
        case 0:
            cout<<"Exit.."<<endl;
            break;
        case 1:
            c=new Mastercard(cardno);
            c->check();
            break;
        case 2:
            c=new Visa(cardno);
            c->check();
            break;
        case 3:
            c=new American(cardno);
            c->check();
            break;
        default:
            break;
        }
    } while (choice!=0);
    
    return 0;
}