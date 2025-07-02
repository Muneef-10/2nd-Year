#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int>> pq;
    int n,z;
    cout<<"Enter number of elements in vector: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter "<<n<<" values"<<endl;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
       cin>>v[i];
       pq.push(v[i]);
    }
    int ts=0;
    while(pq.size() > 1)
    {
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        z=x+y;
        ans.push_back(z);
        ts+=z;
        pq.push(z);
        
    }
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    cout<<endl<<"Total cost: "<<ts;
    
    return 0;
}