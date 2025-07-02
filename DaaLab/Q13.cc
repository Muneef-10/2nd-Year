#include <bits/stdc++.h>
using namespace std;

#define INF 1e9 // A large number representing infinity

void floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist = graph;

    // Floyd-Warshall main algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Print the shortest distance matrix
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF" << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    // Initialize the adjacency matrix
    vector<vector<int>> graph(V, vector<int>(V, INF));

    // Distance from a vertex to itself is 0
    for (int i = 0; i < V; i++)
        graph[i][i] = 0;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w; // For undirected graph, also do graph[v][u] = w;
    }

    floydWarshall(graph, V);

    return 0;
}
