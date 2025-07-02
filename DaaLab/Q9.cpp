//BFS and DFS
#include <bits/stdc++.h>

using namespace std;

void bfs(int start, vector<vector<int>> &adj,vector<bool>&visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    cout<<"Bfs Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout<<endl;
}
void dfs(int node,vector<vector<int>> &adj,vector<bool> &visited)
{
    visited[node]=true;
    cout<<node<<" ";
    for(int neighbor: adj[node])
    {
        if(!visited[neighbor])
            dfs(neighbor,adj,visited);
    }
}
int main() 
{
    int n, e;
    cout<<"Enter number of nodes then edges: ";
    cin>>n>>e;
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false); 

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    int start;
    cout << "Enter the starting node for BFS: ";
    cin >> start;

    bfs(start, adj, visited);

    fill(visited.begin(), visited.end(), false);
    cout << "DFS Traversal: ";
    dfs(start, adj, visited);

    return 0;
}
