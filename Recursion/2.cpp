// Printing subsequences whose sum is K

#include<bits/stdc++.h>
using namespace std;
void Subseq(int index,vector<int> arr, vector<int> ans, int n,int sum,int k)
{
    if(index==n)
    {
        if(sum==k)
        {
            for(int i=0;i<ans.size();i++)
                cout<<ans[i]<<" ";
            cout<<endl;
        }
        
        return;
    }
    ans.push_back(arr[index]);
    Subseq(index+1, arr,ans,n,sum+arr[index],k);
    ans.pop_back();
    Subseq(index+1, arr,ans,n,sum,k);
}
int main()
{
    int n,sum=0,k;
    cout<<"Enter size of vector: ";
    cin>>n;
    cout<<"Enter sum: ";
    cin>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int> ans;
    Subseq(0,arr,ans,n,sum,k);
    return 0;
}