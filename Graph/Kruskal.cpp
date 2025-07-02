#include<bits/stdc++.h>
using namespace std;

int FindParent(int u,vector<int>&parent)
{
    if(u==parent[u]) return u;

    return parent[u]=FindParent(parent[u],parent);
    //path compression
}

void UnionRank(int u,int v,vector<int> &parent, vector<int> &rank)
{
    int pu=FindParent(u,parent);
    int pv=FindParent(v,parent);

    if(rank[pu] > rank[pv])
        parent[pv]=pu;

    else if(rank[pu] < rank[pv])
        parent[pu]=pv;

    else
    {
        parent[pv]=pu;
        rank[pu]++;
    }
}

int Krushkal(int vertex, vector<vector<int>> AdjList[])
{
    vector<int> parent(vertex);
    vector<int> rank(vertex,0);
    for (int i = 0; i < vertex; i++)
    {
        parent[i]=i;
    }

    priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < AdjList[i].size(); j++)
        {
            // wt,u,v
            pq.push({AdjList[i][j][1],{i,AdjList[i][j][0]}});
        }
    }
    int cost=0;
    while(!pq.empty())
    {
        int u=pq.top().second.first;
        int v=pq.top().second.second;
        int wt=pq.top().first;
        pq.pop();

        if(FindParent(u,parent)!=FindParent(v,parent))
        {
            cost+=wt;
            UnionRank(u,v,parent,rank);
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
    
    int cost=Krushkal(vertex,AdjList);
    cout<<cost<<endl;
    
    return 0;
}