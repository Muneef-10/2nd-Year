#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;
    vector<int> v(n);
    for(int i=1;i<=n;i++)    
        cin>>v[i];

    for(int i=1;i<=n;i++)    
        cout<<setw(3)<<setfill('0')<<v[i]<<" ";

    for(int i=1;i<=n;i++)    
        cout<<setw(2)<<setfill('0')<<v[i]<<" ";
    return 0;
}