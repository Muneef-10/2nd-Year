/*Define an exception class called “MyNation” that is thrown when a string is not equal to “jai 
hind” or “JAI HIND”. Write a program that implements this exception*/
#include<bits/stdc++.h>
using namespace std;
class MyNation: public exception
{
    public:
    const char *what()
    {
        return "Invalid Input";
    }
    string str;
    MyNation(string s)
    {
        str=s;
    }
};
int main()
{
    string s;
    getline(cin,s);
    try
    {
        if(s=="JAI HIND" || s=="jai hind")
            cout<<"Valid input"<<endl;
        else
            throw MyNation(s);
    }
    catch(MyNation &e)
    {
        cout<<e.what()<<endl;
    }
    return 0;
}