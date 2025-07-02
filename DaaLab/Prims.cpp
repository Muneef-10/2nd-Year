#include<bits/stdc++.h>
using namespace std;
int main()
{
    int vertex,edge;
    cout<<"Enter number of vertices and edges: ";
    cin>>vertex>>edge;
    vector<pair<int,int>> AdjList[vertex];
    int u,v,w;
    cout<<"Enter edges 'from to weight'"<<endl;
    for (int i = 0; i < edge; i++)
    {
        cin>>u>>v>>w;
        AdjList[u].push_back(make_pair(v,w));
        AdjList[v].push_back(make_pair(u,w));
    }
    

}