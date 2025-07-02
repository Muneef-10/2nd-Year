//Function Overloading Same name ke do fn. but different parameter RETURN type badlne se over loading nhi ho paege jaise humner VOID ko badlke INT kia hai

#include<iostream>
using namespace std;
class Loading
{
public:
void sum(string a, string b)
    {
        cout<<a+b<<endl;
    }
    void sum(int a,int b)
    {
        cout<<a+b<<endl;
    }
    void sum(int a,int b,int c)
    {
        cout<<a+b+c<<endl;
    }
    // int sum(int a,int b,int c)  this will produce an error
    // {
    //     return a+b;
    // }
};
int main()
{
    Loading a;
    a.sum(5,8);
    a.sum(4,9,2);
    a.sum("Muneef ","Khan");
}