#include <bits/stdc++.h>
using namespace std;

void Dijkstra(int src, vector<vector<pair<int, int>>> &AdjList) {
    int V = AdjList.size(); 
    vector<int> dist(V, INT_MAX); // distance array
    dist[src] = 0;

    // Min-heap (distance, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        // If the popped distance is not the most recent, skip it
        if (currDist > dist[u])
            continue;

        for (auto &edge : AdjList[u]) {
            int v=edge.first;
            int weight=edge.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }


    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "To node " << i << " -> ";
        if (dist[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}

int main() {
    vector<vector<int>> a(3,vector<int> (3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>a[i][j];
        }
        
    }
    int n=3;
    int mini=1e6,x=-1;
        for(int i=0;i<n;i++)
        {
            if(mini>a[n-1][i])
            {
                mini=a[n-1][i];
                x=i;
            }
        }
    cout<<mini<<" "<<x;
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j <=i; j++)
    //     {
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    
}
