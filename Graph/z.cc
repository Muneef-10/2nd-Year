#include<bits/stdc++.h>
using namespace std;
int parents(int u,vector<int>&parent)
{
    if(parent[u]==u) return u;
    return parent[u]=parents(parent[u],parent);
}

void ranks(int u,int v,vector<int> &rank,vector<int> &parent)
{
    int pu=parents(u,parent);
    int pv=parents(v,parent);
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
    int cost=0;
    vector<int> parent(vertex);
    vector<int> rank(vertex,0);
    for(int i=0;i<vertex;i++)
        parent[i]=i;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < AdjList[i].size(); j++)
        {
            pq.push({AdjList[i][j][1],{i,AdjList[i][j][0]}});
        }
    }
    while(!pq.empty())
    {
        int u=pq.top().second.first;
        int v=pq.top().second.second;
        int wt=pq.top().first;
        pq.pop();
        if(parents(u,parent)!=parents(v,parent))
        {
            cost+=wt;
            ranks(u,v,rank,parent);
        }
    }
    return cost;
    
}
int main()
{
    int vertex,edge;
    cout<<"Enter number of vertices and edges:"<<endl;
    cin>>vertex>>edge;
    vector<vector<int>> AdjList[vertex];

    int u,v,w;
    cout<<"Enter edges: from to weight"<<endl;
    for (int i = 0; i < edge; i++)
    {
        cin>>u>>v>>w;
        AdjList[u].push_back({v,w});
        AdjList[v].push_back({u,w});
    }
    
    int cost=Krushkal(AdjList,vertex);
    cout<<cost<<endl;
    
    return 0;
}
/*
0 1
0 2
1 3
3 4
2 5
2 6*/