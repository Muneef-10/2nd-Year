//DFS

#include<bits/stdc++.h>
using namespace std;
bool IsCycle(int parent,int node,vector<bool> &visited,vector<int> AdjList[])
{
    visited[node]=1;
    for (int i = 0; i < AdjList[node].size(); i++)
    {
        if(AdjList[node][i]==parent)
            continue;
        if(visited[AdjList[node][i]]==1)  //Neighbour node
            return true;
        if(IsCycle(node,AdjList[node][i],visited,AdjList))
            return true;
    }
    return false;
    
}
int main()
{
    int vertex,edges,u,v;
    cout<<"Enter number of vertices and edges: ";
    cin>>vertex>>edges;
    
    vector<int> AdjList[vertex];
    
    cout<<"Enter edges from - to:"<<endl;
    for (int i = 0; i < edges; i++)
    {
        cin>>u>>v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    vector<bool> visited(vertex,0);

    for (int i = 0; i < vertex; i++)
    {
        if(!visited[i] && IsCycle(-1,i,visited,AdjList))
        {
            cout<<"Yes, there is a cycle in this graph"<<endl;
            return 0;
        }
    }
    cout<<"No, there is no a cycle in this graph"<<endl;
}