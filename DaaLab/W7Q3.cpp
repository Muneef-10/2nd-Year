#include<bits/stdc++.h>
using namespace std;

int solve(int src,int dst,int &k,vector<int> &visited,int parent,int &cost)
{
    if(k==0 && src==dst)return 0;
}

int main() {
    int vertex, edge;
    cout << "Enter number of vertices and edges:" << endl;
    cin >> vertex >> edge;

    vector<pair<int, int>> edges; // {weight, {u, v}}
    int u, v, w;
    cout << "Enter edge weight from - to:" << endl;
    for (int i = 0; i < edge; i++) {
        cin >> w >> u >> v;
        // edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end(),greater<>());  //sort(edges.rbegin(), edges.rend()); this is for maximum MST

    vector<int> parent(vertex);
    vector<int> rank(vertex, 0);

    for (int i = 0; i < vertex; i++)
        parent[i] = i;

    int mst_weight = 0;
    cout << "Edges in Minimum Spanning Tree:" << endl;
    // for (auto e : edges) {
    //     w = e.first;
    //     u = e.second.first;
    //     v = e.second.second;

    //     if (Find(parent, u) != Find(parent, v)) {
    //         cout << u << " -- " << v << " == " << w << endl;
    //         mst_weight += w;
    //         // Union(rank, parent, u, v);
    //     }
    // }

    cout << "Total weight of MST: " << mst_weight << endl;

    return 0;
}
