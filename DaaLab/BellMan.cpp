// #include<bits/stdc++.h>
// using namespace std;

// bool bellmanFord(int V, int start, vector<pair<int, pair<int, int>>>& edges, vector<int>& dist)
// {
//     dist.assign(V,INT_MAX);
//     dist[start]=0;

//     for (int i = 1; i <= V - 1; i++) {
//         for (int j = 0; j < V; j++) {
//             int u = edges[j].first;
//             int v = edges[j].second.first;
//             int wt = edges[j].second.second;
//             if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
//                 dist[v] = dist[u] + wt;
//             }
//         }
//     }

//     for (int u = 0; u < V; ++u)
//     {
//         if(dist[u] == INT_MAX) continue;
//         for(auto neighbour: edges[u])
//         {
//             int v=neighbout.first;
//         }
//     }
    
    
// }
// int main()
// {
//     int vertex,edge;
//     cout<<"Enter number of vertices and edges:"<<endl;
//     cin>>vertex>>edge;
//     vector<pair<int,int>> AdjList[vertex];
//     int u,v,weight;
//     cout<<"Enter edges from - to and weight:"<<endl;
//     for (int i = 0; i < edge; i++)
//     {
//         cin>>u>>v>>weight;
//         AdjList[u].push_back(make_pair(v,weight));
//         AdjList[v].push_back(make_pair(u,weight));
//     }
    
    

//     return 0;
// }