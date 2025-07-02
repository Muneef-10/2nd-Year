//BellmanFord
#include <bits/stdc++.h>
using namespace std;

bool bellmanFord(int V, int E, int start, vector<pair<int, pair<int, int>>>& edges, vector<int>& dist) {
    dist.assign(V, INT_MAX);  
    dist[start] = 0;

    
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].first;
            int v = edges[j].second.first;
            int wt = edges[j].second.second;
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    for (int j = 0; j < E; j++) {
        int u = edges[j].first;
        int v = edges[j].second.first;
        int wt = edges[j].second.second;
        if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            return false;  // Negative weight cycle detected
        }
    }

    return true;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<pair<int, pair<int, int>>> edges;
    cout << "Enter edges in format: from to weight" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, {v, wt}});
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    vector<int> dist;
    if (bellmanFord(V, E, start, edges, dist)) {
        cout << "Shortest distances from vertex " << start << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "To " << i << ": ";
            if (dist[i] == INT_MAX)
                cout << "INF\n";
            else
                cout << dist[i] << endl;
        }
    } else {
        cout << "Graph contains a negative weight cycle.\n";
    }

    return 0;
}
