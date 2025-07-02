#include<bits/stdc++.h>
using namespace std;
void CountSort(vector<int> &v,int place)
{
    vector<int> freq(10,0);
    vector<int> ans(v.size());
    for (int i = 0; i < v.size(); i++)
        freq[(v[i]/place)%10]++;

    for (int i = 1; i < 10; i++)
        freq[i]+=freq[i-1];
    
    for (int i = v.size()-1; i>=0; i--)
        ans[--freq[(v[i]/place)%10]]=v[i];
    
    for (int i = 0; i < v.size(); i++)
        v[i]=ans[i];   
    
}
void Radix(vector<int> &v,int size)
{
    int max=*max_element(v.begin(),v.end());
    for(int place=1;max/place>0;place*=10)
        CountSort(v,place);
    
}
int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<n;i++)
        cin>>v[i];

    Radix(v,n);

    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    return 0;
}