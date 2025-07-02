#include<iostream>
using namespace std;
int fib(int n)
{
    if(n==1 || n==2) return n-1;
    int a= fib(n-1)+fib(n-2);
    return a;
}
int main()
{
    int n;
    cout<<"Enter number: ";
    cin>>n;
    int x=fib(n);
    cout<<"Number at "<<n<<"th position in fibonacci series is: "<<x;
    return 0;
}