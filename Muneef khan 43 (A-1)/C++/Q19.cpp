/*Program to demonstrates the visibility of public, protected, and private in different inheritance scenarios:*/
#include<iostream>
using namespace std;

class Base
{
    public:
        int pubvar=1;
    protected:
        int provar=2;
    private:
        int privar=3;
    public:
    void displaybase()
    {
        cout<<"Base class variable values"<<endl;
        cout<<"Public variable: "<<pubvar<<endl;
        cout<<"Protected variable: "<<provar<<endl;
        cout<<"Private variable: "<<privar<<endl;
    }
};
class DerivedPublic: public Base
{
    public:
    void displayDerivedPublic()
    {
        cout<<"\nPublic Derived class"<<endl;
        cout<<"Public variable: "<<pubvar<<endl;
        cout<<"Protected variable: "<<provar<<endl;
        cout<<"Private variable doesnot accessible here"<<endl;
    }
};
class DerivedProtected: protected Base
{
    public:
    void displayDerivedProtected()
    {
        cout<<"\nProtected Derived class"<<endl;
        cout<<"Public variable: "<<pubvar<<endl;
        cout<<"Protected variable: "<<provar<<endl;
        cout<<"Private variable doesnot accessible here"<<endl;
    }
};
class DerivedPrivate: private Base
{
    public:
    void displayDerivedPrivate()
    {
        cout<<"\nPrivate Derived class"<<endl;
        cout<<"Public variable: "<<pubvar<<endl;
        cout<<"Protected variable: "<<provar<<endl;
        cout<<"Private variable doesnot accessible here"<<endl;
    }
};
int main()
{
    Base baseobj;
    baseobj.displaybase();

    DerivedPublic pubobj;
    pubobj.displayDerivedPublic();

    DerivedProtected proobj;
    proobj.displayDerivedProtected();

    DerivedPrivate priobj;
    priobj.displayDerivedPrivate();
    cout<<endl<<"*************************************************************"<<endl;
    cout<<"Program Prepared & Executes by:Muneef Khan, Class Roll no.: 43"<<endl;
    cout<<"*************************************************************"<<endl;
    return 0;
}