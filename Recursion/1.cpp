// Print all Subsequence of an array

#include<bits/stdc++.h>
using namespace std;
void Subseq(int ind, vector<int> ans, vector<int> v,int n)
{
    if(ind>=n)
    {
        cout<<"{ ";
        for (int i = 0; i < ans.size(); i++)
            cout<<ans[i]<<" ";
        cout<<"}"<<endl;
        return;        
    }
    ans.push_back(v[ind]);
    Subseq(ind+1, ans, v, n);
    ans.pop_back();
    Subseq(ind+1, ans, v, n);
    return;
}
int main()
{
    int n;
    cout<<"Enter size of vector: ";
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    vector<int> ans;
    Subseq(0,ans,v,n);
    return 0;
}