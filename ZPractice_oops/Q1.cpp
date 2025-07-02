//1x1=1  2x1=2
//1x2=2  2x2=4
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number: ";
    cin>>n;
    for (int i = 1; i <=10; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            cout<<j<<"x"<<i<<"="<<j*i<<"  ";
        }
        cout<<endl; 
    }
    
    return 0;
}