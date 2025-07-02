//BFS
#include<bits/stdc++.h>
using namespace std;
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
    vector<int>visited(nodes+1,0);
    queue<int> q;
    q.push(s);
    visited[s]=1;
    while (!q.empty())
    {
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for (int i = 1; i <=nodes; i++)
        {
            if(adj[node][i]==1 && !visited[i])
            {
                q.push(i);
                visited[i]=1;
            }
        }
    }
       
    return 0;
}