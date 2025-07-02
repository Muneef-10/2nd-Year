/*Q-11)Design a class to represent bank account. Includes the following members:
• Name of depositor
• Account number
• Type of account
• Balance amount in the account
Write a program to incorporate the constructor to provide initial values*/

#include<bits/stdc++.h>
using namespace std;

class Bank
{
    private:
    string name;
    string tacc;
    long acc;
    long bal;

    public:
    Bank(string name,string tacc,long acc, long bal)
    {
        this->name=name;
        this->tacc=tacc;
        this->acc=acc;
        this->bal=bal;
    }

    void display()
    {
        cout<<endl<<"\t*****Union Bank Of India*****"<<endl;
        cout<<"Name of bank account holder:-  "<<name<<endl<<"Account number:-  "<<acc<<endl<<"Account type:-  "<<tacc<<endl<<"Balance amount:-  "<<bal<<endl<<endl;
    }

    void deposit(int x)
    {
        bal=bal+x;
        cout<<"deposited Rs:"<<x<<" current balance in your account is Rs:"<<bal<<endl<<endl;
    }

    void withdraw(int x)
    {
        bal=bal-x;
        cout<<"Withdraw Rs:"<<x<<" current balance in your account is Rs:"<<bal<<endl<<endl;
    }
};
int main()
{
    Bank b1("Sahitya","Saving",569621,8546);
    Bank b2("Arpit","Current",619964,7354);
    Bank b3("Anurag","Current",729354,10536);

    int n,a;
    do
    {
        cout<<"Press [1] to check your details"<<endl;
        cout<<"Press [2] for deposit an amount"<<endl;
        cout<<"Press [3] for withdraw an amount"<<endl;
        cout<<"Press [0] for exit"<<endl;
        cin>>n;

        switch(n)
        {
            case 0:
                cout<<"Exit..";
                break;

            case 1:
                cout<<"Enter last 4 digit of your account number: ";
                cin>>a;
                if(a==9621) b1.display();
                else if(a==9964) b2.display();
                else if(a==9354) b3.display();
                else cout<<"Inavlid input, try again..."<<endl;
                break;

            case 2:
                cout<<"Enter last 4 digit of your account number: ";
                cin>>a;
                if(a==9621) 
                {
                    int x;
                    cout<<"Enter amount for deposit: "<<endl;
                    cin>>x;
                    b1.deposit(x);
                }
                else if(a==9964)
                {
                    int x;
                    cout<<"Enter amount for deposit: "<<endl;
                    cin>>x;
                    b2.deposit(x);
                } 
                else if(a==9354) 
                {
                    int x;
                    cout<<"Enter amount for deposit: "<<endl;
                    cin>>x;
                    b3.deposit(x);
                }
                else cout<<"Inavlid input, try again..."<<endl;
                break;

            case 3:
                cout<<"Enter last 4 digit of your account number: ";
                cin>>a;
                if(a==9621) 
                {
                    int x;
                    cout<<"Enter amount for withdraw: "<<endl;
                    cin>>x;
                    b1.withdraw(x);
                }
                else if(a==9964)
                {
                    int x;
                    cout<<"Enter amount for withdraw: "<<endl;
                    cin>>x;
                    b2.withdraw(x);
                } 
                else if(a==9354) 
                {
                    int x;
                    cout<<"Enter amount for withdraw: "<<endl;
                    cin>>x;
                    b3.withdraw(x);
                }
                else cout<<"Inavlid input, try again..."<<endl;
                break;

            default:
                cout<<"Invalid input, try again..."<<endl;
                break;

        }
    } while (n!=0);
    
    cout<<endl<<"*************************************************************"<<endl;
    cout<<"Program Prepared & Executes by:Muneef Khan, Class Roll no.: 43"<<endl;
    cout<<"*************************************************************"<<endl;
    return 0;
}