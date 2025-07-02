// Undirected and Weighted
// vector<vector<bool>> AdjMat(vertex/*row*/, vector<bool>(vertex/*column*/,0))

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int vertex,edges;
    cout<<"Enter number of vertices and edges:"<<endl;
    cin>>vertex>>edges;

    vector<vector<int>> AdjMat(vertex, vector<int>(vertex,0));

    int u,v,w;
    cout<<"Enter edges from - to and weight:"<<endl;
    for (int i = 0; i < edges; i++)
    {
        cin>>u>>v>>w;
        AdjMat[u][v]=w;
        AdjMat[v][u]=w;
    }
    
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
            cout<<AdjMat[i][j]<<" ";
        cout<<endl;        
    }
    
    return 0;
}