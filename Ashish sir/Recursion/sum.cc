#include<iostream>
using namespace std;
int sum(int n)
{
    if(n==1) return 1;
    return n+sum(n-1);
}
int main()
{
    int n;
    cout<<"Enter number of disk: ";
    cin>>n;
    int x=sum(n);
    cout<<"Sum of number: "<<x;
    return 0;
}