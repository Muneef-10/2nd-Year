#include<bits/stdc++.h>
using namespace std;

int Find(vector<int>& parent, int u) {
    if (parent[u] != u)
        parent[u] = Find(parent, parent[u]);
    return parent[u];
}

void Union(vector<int>& rank, vector<int>& parent, int u, int v) {
    int x = Find(parent, u);
    int y = Find(parent, v);

    // if (x == y) return; // already in same set
    if (rank[x] < rank[y])
        parent[x] = y;
    else if (rank[x] > rank[y])
        parent[y] = x;
    else {
        parent[y] = x;
        rank[x]++;
    }
}

int main() {
    int vertex, edge;
    cout << "Enter number of vertices and edges:" << endl;
    cin >> vertex >> edge;

    vector<pair<int, pair<int, int>>> edges; // {weight, {u, v}}
    int u, v, w;
    cout << "Enter edge weight from - to:" << endl;
    for (int i = 0; i < edge; i++) {
        cin >> w >> u >> v;
        edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end(),greater<>());  //sort(edges.rbegin(), edges.rend()); this is for maximum MST

    vector<int> parent(vertex);
    vector<int> rank(vertex, 0);

    for (int i = 0; i < vertex; i++)
        parent[i] = i;

    int mst_weight = 0;
    cout << "Edges in Minimum Spanning Tree:" << endl;
    for (auto e : edges) {
        w = e.first;
        u = e.second.first;
        v = e.second.second;

        if (Find(parent, u) != Find(parent, v)) {
            cout << u << " -- " << v << " == " << w << endl;
            mst_weight += w;
            Union(rank, parent, u, v);
        }
    }

    cout << "Total weight of MST: " << mst_weight << endl;

    return 0;
}
