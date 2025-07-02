#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];
int Helper(vector<int> weight, vector<int> value, int W, int n)
{
    if(W==0 || n==0) return 0;
    if(t[n][W]!=-1) return t[n][W];
    
    if(weight[n-1] > W) return t[n][W]= Helper(weight, value, W, n-1);

    return t[n][W]=max(value[n-1]+Helper(weight,value,W-weight[n-1],n-1) , Helper(weight,value,W,n-1));
}
int main()
{
    int n;
    cout<<"Enter number of values: ";
    cin>>n;
    vector<int> weight(n);
    vector<int> value(n);
    cout<<"Enter weight"<<endl;
    for(int i=0;i<n;i++)
        cin>>weight[i];
    
    cout<<"Enter their values"<<endl;
    for(int i=0;i<n;i++)
        cin>>value[i];
        
    memset(t,-1,sizeof(t));
    cout<<Helper(weight,value,10,n);
    return 0;
}