#include<bits/stdc++.h>
using namespace std;
vector<int> Dijkstras(int vertex,vector<vector<int>> AdjList[],int src)
{
    vector<bool> explore(vertex,0);
    vector<int> dist(vertex,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    dist[src]=0;
    pq.push({0,src});
    
    while(!pq.empty())
    {
        int node=pq.top().second;
        pq.pop();
        
        if(explore[node]==1) 
            continue;
        
        explore[node]=1;

        for (int i = 0; i < AdjList[node].size(); i++)
        {
            int neighbour=AdjList[node][i][1];
            int weight=AdjList[node][i][0];
            if(!explore[neighbour] && weight+dist[node]< dist[neighbour])
            {
                dist[neighbour]=weight+dist[node];
                pq.push({dist[neighbour],neighbour});
            }
        }
    }
    return dist;
}
int main()
{
    int vertex,edge,src;
    cout<<"Enter number of vertices and edges:";
    cin>>vertex>>edge;
    vector<vector<int>> AdjList[vertex];
    int u,v,w;
    cout<<"Enter edges from - to - weight"<<endl;
    for (int i = 0; i < edge; i++)
    {
        cin>>u>>v>>w;
        AdjList[u].push_back({w,v});
        AdjList[v].push_back({w,u});
    }

    cout<<"Enter source node: ";
    cin>>src;

    vector<int> dist=Dijkstras(vertex,AdjList,src);

    for(int i=0;i<dist.size();i++)
    {
        cout<<src<<"->"<<i<<", "<<dist[i]<<endl;
    }
    return 0;
}