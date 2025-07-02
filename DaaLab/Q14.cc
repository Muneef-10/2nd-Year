#include <bits/stdc++.h>
using namespace std;

void primMST(int vertex, vector<pair<int, int>> AdjList[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> key(vertex, INT_MAX);
    vector<int> parent(vertex, -1);
    vector<bool> inMST(vertex, false);

    int src = 0;
    key[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        for (auto it : AdjList[u]) {
            int v=it.first;
            int weight=it.second;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Output the MST
    cout << "Minimum Spanning Tree edges:\n";
    int total_weight = 0;
    for (int i = 1; i < vertex; i++) {
        cout << parent[i] << " - " << i << " (Weight: " << key[i] << ")\n";
        total_weight += key[i];
    }
    cout << "Total weight of MST: " << total_weight << endl;
}

int main() {
    int vertex, edge;
    cout << "Enter number of vertices and edges: ";
    cin >> vertex >> edge;

    vector<pair<int, int>> AdjList[vertex];
    int u, v, w;
    cout << "Enter edges 'from to weight':\n";
    for (int i = 0; i < edge; i++) {
        cin >> u >> v >> w;
        AdjList[u].push_back({v, w});
        AdjList[v].push_back({u, w});
    }

    primMST(vertex, AdjList);

    return 0;
}
