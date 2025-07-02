//cycle detection

#include<bits/stdc++.h>
using namespace std;
bool IsCycle(int start, vector<vector<int>> &adj,vector<bool> &visited)
{
    queue<pair<int,int>> q;
    q.push({start,-1});
    visited[start]=true;

    while(!q.empty())
    {
        int node =q.front().first;
        int parent=q.front().second;
        q.pop();

        for(int neighbour: adj[node])
        {
            if(!visited[neighbour])
            {
                visited[neighbour]=true;
                q.push({neighbour,node});
            }
            else if(neighbour!=parent)
                return true;
        }
    }
    return false;
}
int main()
{
    int n,e;
    cout<<"Enter number of nodes and edges: ";
    cin>>n>>e;
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);
    cout<<"Enter edges from - to:"<<endl;
    for (int i = 0; i < e; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool f=false;
    for (int i = 0; i < n; i++)
    {
        if(visited[i]==0)
        {
        if(IsCycle(i,adj,visited))
        {
            f=true;
        }
    }
            
    }
    
    return 0;
}