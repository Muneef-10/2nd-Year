#include<iostream>
using namespace std;
class Tellcall
{
    private:
        string phno;
        string sname;
        int n;
        float amt;

    public:
        Tellcall(string sname,string phno,int n)
        {
            this->sname=sname;
            this->phno=phno;
            this->n=n;
        }
        void compute()
        {
            if(n<=100) amt=500;
            else if(n>100 && n<=200) amt=(n*1)+500;
            else if(n>200 && n<=300) amt=(n*1.2)+500;
            else  amt=(n*1.5)+500;
        }
        void display()
        {
            cout<<"Name: "<<sname<<endl;
            cout<<"Phone no.: "<<phno<<endl;
            cout<<"Bill amount: Rs "<<amt<<endl;
        }
};
int main()
{
    Tellcall t1("Ayan","123654789",253);
    Tellcall t2("Subhan","953621478",326);

    t1.compute();
    t2.compute();

    t1.display();
    t2.display();
    return 0;
}