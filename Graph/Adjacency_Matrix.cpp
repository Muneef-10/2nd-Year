// Undirected and unweighted
// vector<vector<bool>> AdjMat(vertex/*row*/, vector<bool>(vertex/*column*/,0))

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int vertex,edges;
    cout<<"Enter number of vertices and edges:"<<endl;
    cin>>vertex>>edges;

    vector<vector<bool>> AdjMat(vertex, vector<bool>(vertex,0));
    int u,v;
    cout<<"Enter edges from - to:"<<endl;
    for (int i = 0; i < edges; i++)
    {
        cin>>u>>v;
        AdjMat[u][v]=1;
        AdjMat[v][u]=1;
    }
    
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
            cout<<AdjMat[i][j]<<" ";
        cout<<endl;        
    }
    
    return 0;
}