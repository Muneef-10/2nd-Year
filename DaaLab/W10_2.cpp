#include<bits/stdc++.h>
using namespace std;
class Solve
{
    public:
    int MaxNo(vector<int> tt, vector<int> dl)
    {
        int t=0,n=tt.size(),count=0;
        vector<pair<int,int>> td(n);
        for(int i=0;i<n;i++)
        {
            td[i]={dl[i],tt[i]};
        }
        sort(td.begin(),td.end());
        for (int i = 0; i < n; i++)
        {
            if(t+td[i].second <=td[i].first)
            {
                count++;
                t=t+td[i].second;
            }
        }
        return count;
    }
};

int main()
{
    vector<int> tt={2, 1, 3, 2, 2, 2, 1};
    vector<int> dl={2, 3, 8, 6, 2, 5, 3};
    Solve sr;
    cout<<sr.MaxNo(tt,dl);
    return 0;
}