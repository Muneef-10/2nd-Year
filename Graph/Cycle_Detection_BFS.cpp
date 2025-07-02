#include<bits/stdc++.h>
using namespace std;
bool IsCycle(int node,vector<bool> &visited,vector<int> AdjList[])
{
    queue<pair<int,int>> q;
    q.push(make_pair(-1,node));
    visited[node]=1;
    while(!q.empty())
    {
        pair<int,int> ver=q.front();
        q.pop();
        for (int i = 0; i < AdjList[ver.second].size(); i++)
        {
            if(AdjList[ver.second][i]==ver.first)
                continue;
            if(visited[AdjList[ver.second][i]]==1)
                return true;
        
            q.push(make_pair(ver.second,AdjList[ver.second][i]));
            visited[AdjList[ver.second][i]]=1;
        }
        
    }
    return false;
}
int main()
{
    int vertex,edges,u,v;
    cout<<"Enter number of vertices and edges:"<<endl;
    cin>>vertex>>edges;

    vector<int> AdjList[vertex];

    cout<<"Enter edges from - to"<<endl;
    for (int i = 0; i < edges; i++)
    {
        cin>>u>>v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    vector<bool> visited(vertex,0);
    for (int i = 0; i < vertex; i++)
    {
        if(!visited[i] && IsCycle(i,visited,AdjList))
        {
            cout<<"Yes, there is a cycle in this graph"<<endl;
            return 0;
        }
    }
    cout<<"No, there is no a cycle in this graph"<<endl;
    
    
    return 0;
}