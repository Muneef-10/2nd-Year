#include<iostream>
using namespace std;
class Bank
{
    private:    
        string name;
        string accno;
        string typeacc;
        float bal;
    public:
    Bank(string name,string accno,string typeacc,float bal)
    {
        this->name=name;
        this->accno=accno;
        this->typeacc=typeacc;
        this->bal=bal;
    }
    void deposit()
    {
        int n;
        cout<<"Enter amount: ";
        cin>>n;
        bal=bal+n;
    }
    void withdraw()
    {
        int n;
        cout<<"Enter amount: ";
        cin>>n;
        if(n<bal) bal=bal-n;
        else cout<<"Your amount is not sufficient, your current balance is"<<bal;
    }
    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Acc.No.: "<<accno<<endl;
        cout<<"Type: "<<typeacc<<endl;
        cout<<"Balance: "<<bal<<endl;
    }
};
int main()
{
    int a,x;
    Bank b1("Ayan","265489","Saving",2541);
    Bank b2("Subhan","385424","Curent",3441);
    Bank b3("Zakariya","595438","Saving",4641);
    
    do
    {
        cout<<"Press [1] to deposit an amount"<<endl;
        cout<<"Press [2] to withdraw amount"<<endl;
        cout<<"Press [3] to display details"<<endl;
        cout<<"Press [0] to exit"<<endl;
        cin>>a;
        switch(a)
        {
            case 0:
                cout<<"Exit.."<<endl;
                break;
            case 1:
                cout<<"Enter last 2 digit of your acc no.: ";
                cin>>x;
                if(x==89) b1.deposit();
                else if(x==24) b2.deposit();
                else if(x==38) b3.deposit();
                else cout<<"Inalivd account number"<<endl;
                break;
            case 2:
                cout<<"Enter last 2 digit of your acc no.: ";
                cin>>x;
                if(x==89) b1.withdraw();
                else if(x==24) b2.withdraw();
                else if(x==38) b3.withdraw();
                else cout<<"Inalivd account number"<<endl;
                break;
            case 3:
                cout<<"Enter last 2 digit of your acc no.: ";
                cin>>x;
                if(x==89) b1.display();
                else if(x==24) b2.display();
                else if(x==38) b3.display();
                else cout<<"Inalivd account number"<<endl;
                break;
            default:
                cout<<"Invalid input"<<endl;
                break;
        }
    } while (a!=0);
    
    return 0;
}