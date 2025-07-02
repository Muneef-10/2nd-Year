#include <bits/stdc++.h>
using namespace std;

bool PG(int v, vector<vector<int>> &AdjList) {
    queue<int> q;
    vector<int> color(v, -1);

    for (int j = 0; j < v; j++) {
        if (color[j] == -1) {  // Only process unvisited components
            q.push(j);
            color[j] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int i = 0; i < AdjList[node].size(); i++) {
                    int neighbor = AdjList[node][i];

                    if (color[neighbor] == -1) { // If unvisited, color it
                        q.push(neighbor);
                        color[neighbor] = (color[node] + 1) % 2;
                    } 
                    else if (color[node] == color[neighbor]) { // Conflict in colors
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int vertex, edges;
    cout << "Enter number of vertices and edges\n";
    cin >> vertex >> edges;

    vector<vector<int>> AdjList(vertex); // Fix: Use vector of vectors

    int u, v;
    cout << "Enter edges\n";
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    if (PG(vertex, AdjList)) 
        cout << "YES";
    else 
        cout << "NO";

    return 0;
}
