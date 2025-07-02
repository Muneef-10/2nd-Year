/* Write a program in C++ to display the sum of the series [ 9 + 99 + 999 + 9999 ...]
Sample Output:
Input number of terms: 5
9 99 999 9999 99999
The sum of the Series = 111105*/

#include<iostream>
using namespace std;
int pow(int p)
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
    cout<<"Enter number of terms: ";
    cin>>n;
    int a[n]={0},sum=0;
    for (int i = 0; i < n; i++)
    {
        x=x+(9*pow(i));
        cout<<x<<" ";
        a[i]=x;
    }
    for (int i = 0; i < n; i++)
    {
        sum=sum+a[i];
    }
    cout<<endl<<"Sum of series: "<<sum;
    
    
    return 0;
}