#include<iostream>
using namespace std;
int sum_of_digit(int n)
{
    if(n/10==0) return n;
    return n%10+sum_of_digit(n/10);
}
int main()
{
    int n;
    cout<<"Enter number: ";
    cin>>n;
    n=sum_of_digit(n);
    cout<<n;
    return 0;
}