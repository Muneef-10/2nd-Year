/*Q-10) A class Telcall calculates the monthly phone bill of a consumer. Some of the members of the class are given below:
Class name: 
Data members/instance variable : phno(phone Number), sname(subscriber Name ) n(number of calls made) and amt (bill amount).
Member function/methods: 
TelCall() : Parameterized constructor to assign values to data members.
Void compute( ) : to calculate the phone bill amount base on the slabs given below.
Void display( ) : to display the details in the specified format.
Number of calls Rate
1 – 100 Rs. 500/- rental charge only
101 – 200 Rs 1.00 per call + rental charge
201-300 Rs. 1.20 per call + rental charge
Above 300 Rs. 1.50 per call + rental charge*/

#include<bits/stdc++.h>
using namespace std;
class Tellcall
{
    private:
        string phno;
        string sname;
        int n;
        float amt=0;
    public:
    Tellcall(string sname,string phno,int n)
    {
        this->sname = sname;
        this->phno = phno;
        this->n = n;
    }

    void compute()
    {
        if(n<=100) amt = 500;
        else if(n<=200 && n>100) amt=n*1+500;
        else if(n<=300 && n>200) amt=(n*1.2)+500;
        else amt = (n*1.5)+500;
    }

    void display()
    {
        cout<<"Consumer name :- "<<sname<<endl;
        cout<<"Phone number :- "<<phno<<endl;
        cout<<"Number of calls :- "<<n<<endl;
        cout<<"Bill amount :- Rs "<<amt<<endl<<endl;
    }

};
int main()
{
    Tellcall t1("Ayan","9546987416",300);
    Tellcall t2("Pranjal","9225687321",156);
    Tellcall t3("Sakib","8246926483",267);
    Tellcall t4("Abhishek","7284698743",354);

    t1.compute();
    t2.compute();
    t3.compute();
    t4.compute();

    cout<<endl<<"*****PHONE BILL*****"<<endl<<endl;
    t1.display();
    t2.display();
    t3.display();
    t4.display();
    
    cout<<endl<<"*************************************************************"<<endl;
    cout<<"Program Prepared & Executes by:Muneef Khan, Class Roll no.: 43"<<endl;
    cout<<"*************************************************************"<<endl;
    return 0;
}