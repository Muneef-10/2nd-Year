#include <iostream> 
#include <vector> 
using namespace std; 

void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited) { 
    visited[v] = true; 
    for(int u : adj[v]) { 
        if(!visited[u]) 
            dfs(u, adj, visited); 
    } 
} 
int findMotherVertex(int V, vector<vector<int>>& adj) { 
    vector<bool> visited(V, false); 
    int lastV = 0; 
 
    for(int i = 0; i < V; i++) { 
        if(!visited[i]) { 
            dfs(i, adj, visited); 
            lastV = i; 
        } 
    } 
 
    for(int i = 0; i < V; i++) visited[i] = false; 
 
 
    dfs(lastV, adj, visited); 
    for(bool v : visited) { 
        if(!v) return -1;
    } 
    return lastV; 
} 
 
int main() { 
    int V, E; 
    cout << "Enter number of vertices: "; 
    cin >> V; 
    cout << "Enter number of edges: "; 
    cin >> E; 
    vector<vector<int>> adj(V); 
    cout << "Enter edges (u v) for directed edge u -> v:" << endl; 
    for(int i = 0; i < E; i++) { 
        int u, v; 
        cin >> u >> v; 
        adj[u].push_back(v); 
    } 
 
    int mother = findMotherVertex(V, adj); 
    if(mother == -1) 
        cout << "No mother vertex exists in the graph." << endl; 
    else 
        cout << "Mother vertex is: " << mother << endl; 
    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;

    return 0; 
} 