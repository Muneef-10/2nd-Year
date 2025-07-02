#include<bits/stdc++.h>
using namespace std;
int Helper(vector<int> weight, vector<int> value, int W, int n)
{
    int t[n+1][W+1];
    for (int i = 0; i < n+1; i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0||j==0)
                t[i][j]=0;
        }
    }
    
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < W+1; j++)
        {
            if(weight[i-1] <= j)
                t[i][j]=max(value[i-1]+t[i-1][j-weight[i-1]] , t[i-1][j]);
            else
                t[i][j]=t[i-1][j];
        }
        
    }
    return t[n][W];
    
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
        
    cout<<Helper(weight,value,10,n);
    return 0;
}