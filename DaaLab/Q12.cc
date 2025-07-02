#include<bits/stdc++.h>
using namespace std;
const int INF =999;
void floydWarshall(vector<vector<int>> &dist)
{
    int v=dist.size();

    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if(dist[i][k]!=INF && dist[k][j]!=INF)
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }           
        }
    }
    
}
int main() 
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V;

    // Initialize the adjacency matrix
    vector<vector<int>> dist(V, vector<int>(V));

    // Distance from a vertex to itself is 0
    cout<<"Enter adjency matrix(Use "<<INF<<"for no direct edges";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin>>dist[i][j];
            if(i==j)
                dist[i][j]=0;
        }
        
    }

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w; // For undirected graph, also do graph[v][u] = w;
    }

    floydWarshall(graph, V);

    return 0;
}