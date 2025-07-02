// Dijkstra Algorithm
#include<bits/stdc++.h>
#include <climits>
using namespace std;
vector<int> dijkstra(int V, int start, vector<vector<pair<int, int>>> &adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if (dist[v] > currentDist + w) {
                dist[v] = currentDist + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() 
{
    int V,E;
    cin>>V>>E;
    vector<vector<pair<int, int>>> adj(V);
  
    for (int i=0; i<E; i++) 
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
    }
    int source;
    cout << "Enter source node: ";
    cin >> source;
    vector<int> distance = dijkstra(V, source, adj);
    for(int i=0;i<V;i++)
    {
       cout<<source<<" "<<distance[i]; 
    }
    return 0;
}