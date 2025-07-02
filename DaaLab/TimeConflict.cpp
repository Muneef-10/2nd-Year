#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans=0;
    vector<pair<int,int>> tm;
    // priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    cout<<"Enter number of activities: ";
    cin>>n;
    cout<<"Enter starting and ending time:"<<endl;
    int a,b;
    for (int i = 0; i < n; i++)
    {
        cin>>a>>b;
        tm.push_back({b,a});
    }
    
    sort(tm.begin(), tm.end());

    int finish=-1;

    for(int i=0;i<n;i++)
    {
        if(tm[i].second > finish)  //starting time = tm[i].second
        {
            finish=tm[i].first;
            ans++;
        }
    }

    cout<<ans;

    return 0;
}