#include<bits/stdc++.h>
using namespace std;
bool DFS(int node,int end,vector<int> &visited,vector<int> AdjList[])
{
    if(node==end) return true;

    visited[node]=1;
    for (int i = 0; i < AdjList[node].size(); i++)
    {
        if(visited[AdjList[node][i]]!=1)
        {
            if(DFS(AdjList[node][i],end,visited,AdjList))
            return true;
        }
    }
    return false;
}
int main()
{
    int vertex,edges;
    cout<<"Enter number of vertices and edges:";
    cin>>vertex>>edges;
    vector<int> AdjList[vertex];
    int u,v;
    cout<<"Enter edges from - to\n";
    for (int i = 0; i < edges; i++)
    {
        cin>>u>>v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    int src,dst;
    cout<<"Enter source and destination node\n";
    cin>>src>>dst;

    vector<int> visited(vertex,0);
    
    if(DFS(src,dst,visited,AdjList)) cout<<"Yes";
    else cout<<"No";
    return 0;
}