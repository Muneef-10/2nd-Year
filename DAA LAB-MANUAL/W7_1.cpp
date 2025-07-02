#include<bits/stdc++.h>
using namespace std;
vector<int> Dijkstra(int vertex, vector<vector<int>> AdjList[], int src,vector<int> &parent)
{
    vector<int>  explore(vertex,0);
    vector<int>  dist(vertex,INT_MAX);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty())
    {
        int node=pq.top().second;
        pq.pop();

        if(explore[node]==1) continue;
        
        explore[node]=1;
        for(int i=0; i<AdjList[node].size(); i++)
        {
            int wt=AdjList[node][i][0];
            int neighbour=AdjList[node][i][1];
            if(!explore[neighbour] && dist[node]+wt < dist[neighbour])
            {
                dist[neighbour] = dist[node]+wt;
                parent[neighbour]=node;
                pq.push({dist[neighbour],neighbour});
            } 
        }
    }
    return dist;
}

void print(int node, vector<int> parent)
{
    if(node==-1) return;
    cout<<node<<" ";
    print(parent[node],parent);
}

int main()
{
    int vertex, edge;
    cout<<"Enter number of vertices and edges: ";
    cin>>vertex>>edge;
    vector<vector<int>> AdjList[vertex];
    
    int u,v,w;
    cout<<"Enter edges from - to:"<<endl;
    for (int i = 0; i < edge; i++)
    {
        cin>>u>>v>>w;
        AdjList[u].push_back({w,v});
        AdjList[v].push_back({w,u});
    }
    
    int source;
    cout<<"Enter source: ";
    cin>>source;
    vector<int>  parent(vertex,-1);
    vector<int> dist=Dijkstra(vertex,AdjList,source,parent);

    for (int i = 0; i < dist.size(); i++)
    {
        cout<<i<<"-"<<source<<" path-> ";
        print(i,parent);
        cout<<"Distance->"<<dist[i]<<endl;
    }
    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;
    return 0;
}