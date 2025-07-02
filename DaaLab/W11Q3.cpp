#include<bits/stdc++.h>
using namespace std;
bool Sum(vector<int> v,int sum, int n)
{
    if(sum==0) return true;
    if(n==0) return false;
    if(v[n-1]>sum) return Sum(v,sum,n-1);

    return (Sum(v,sum-v[n-1],n-1)|| Sum(v,sum,n-1));
}
int main()
{
    int n,sum=0;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    if (sum % 2 != 0) 
    {
        cout << "No";
        return 0;
    }
    sum/=2;
    if(Sum(v,sum,n))
        cout<<"Yes";
    else cout<<"No";
    return 0;
}