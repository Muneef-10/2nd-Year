//DFS
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>> &adj,vector <bool> &visited)
{
    cout<<node<<" ";
    visited[node]=1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if(adj[node][i] && !visited[i])
            dfs(i,adj,visited);
    }    
}
int main()
{
    int nodes,edge;
    cout<<"Enter number of nodes and edges:"<<endl;
    cin>>nodes>>edge;
    vector<vector<int>> adj(nodes+1,vector<int>(nodes+1,0));
    int u,v;
    for (int i = 0; i < edge; i++)
    {
        cout<<"Enter from -> to nodes\n";
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    for (int i = 0; i <=nodes; i++)
    {
        for (int j = 0; j <=nodes; j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
        
    }
    int s;
    cout<<"Enter source node: ";
    cin>>s;
    vector<bool>visited(nodes+1,0);
    dfs(s,adj,visited);
       
    return 0;
}