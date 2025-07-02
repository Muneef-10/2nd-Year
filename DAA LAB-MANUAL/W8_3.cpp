#include<bits/stdc++.h>
using namespace std;
int FindParent(int u, vector<int> &parent)
{
    if(u==parent[u]) return u;
    return parent[u]=FindParent(parent[u],parent);
}

void Union(int u,int v, vector<int> &parent,vector<int> &rank)
{
    int pu=FindParent(u,parent);
    int pv=FindParent(v,parent);

    if(rank[pu]>rank[pv])
        parent[pv]=pu;
    
    else if(rank[pu]<rank[pv])
        parent[pu]=pv;

    else
    {
        parent[pv]=pu;
        rank[pu]++;
    }
}
int Krushkal(vector<vector<int>> AdjList[],int vertex)
{
    vector<int> parent(vertex);
    vector<int> rank(vertex,0);
    for (int i = 0; i < vertex; i++)
        parent[i]=i;

    int cost =0;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, less<pair<int,pair<int,int>>>> pq;

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < AdjList[i].size(); j++)
            // wt, u,v
            pq.push({AdjList[i][j][1],{i,AdjList[i][j][0]}});
    }
    while(!pq.empty())
    {
        int u=pq.top().second.first;
        int v=pq.top().second.second;
        int wt=pq.top().first;
        pq.pop();

        if(FindParent(u,parent)!=FindParent(v,parent))
        {
            cost+=wt;
            Union(u,v,parent,rank);
        }
    }
    return cost;
}
int main()
{
    int vertex, edge;
    cout<<"Enter number of vertices and edges:"<<endl;
    cin>>vertex>>edge;
    vector<vector<int>> AdjList[vertex];
    int u,v,w;
    cout<<"Enter edge: from to weight"<<endl;
    for (int i = 0; i < edge; i++)
    {
        cin>>u>>v>>w;
        AdjList[u].push_back({v,w});
        AdjList[v].push_back({u,w});
    }

    int cost=Krushkal(AdjList,vertex);
    cout<<"Maximum Spannig Weight: "<<cost;
    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;
    
    return 0;
}