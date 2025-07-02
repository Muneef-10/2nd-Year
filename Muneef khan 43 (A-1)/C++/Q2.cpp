//Q-2) Write a program in C++ to display the sum of the series [ 9 + 99 + 999 + 9999 ...]

#include<bits/stdc++.h>
using namespace std;
int power(int p)
{
    int c=1;
    for (int i = 0; i < p; i++)
    {
       c=10*c; 
    }
    return c;
}
int main()
{
    int n,x=0;
    cout<<"Input Number of terms: ";
    cin>>n;
    int a[n]={0},sum=0;
    for (int i = 0; i < n; i++)
    {
        x=x+(9*power(i));
        cout<<x<<" ";
        a[i]=x;
    }
    for (int i = 0; i < n; i++)
    {
        sum=sum+a[i];
    }
    cout<<endl<<"The sum of the series is: "<<sum;

    cout<<endl<<"*************************************************************"<<endl;
    cout<<"Program Prepared & Executes by:Muneef Khan, Class Roll no.: 43"<<endl;
    cout<<"*************************************************************"<<endl;

    return 0;
}