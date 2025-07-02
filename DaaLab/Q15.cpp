#include<bits/stdc++.h>
using namespace std;
int Find(int u,vector<int> &parent)
{
    if(parent[u]==u) return u;
    return parent[u]=Find(parent[u],parent);
}
void Union(int u,int v,vector<int> parent ,vector<int> rank)
{
    int p1=Find(u,parent);
    int p2=Find(v,parent);
    if(p1==p2) return;
    if(rank[p1]==rank[p2])
    {
        parent[p2]=p1;
        rank[p1]++;
    }
    else if(rank[p1]>rank[p2])
        parent[p2]=p1;
    else
        parent[p1]=p2;
}
int main()
{
    int n=5;
    vector<int> parent(n);
    vector<int> rank(n,0);
    for (int i = 0; i < 5; i++)
    {
        parent[i]=i;
    }
    
    return 0;
}