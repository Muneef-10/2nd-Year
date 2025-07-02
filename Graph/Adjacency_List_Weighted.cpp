//Undirected

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int vertex,edge;
    cout<<"Enter number of vertices and edges:"<<endl;
    cin>>vertex>>edge;
    vector<pair<int,int>> AdjList[vertex];
    int u,v,weight;
    cout<<"Enter edges from - to and weight:"<<endl;
    for (int i = 0; i < edge; i++)
    {
        cin>>u>>v>>weight;
        AdjList[u].push_back(make_pair(v,weight));
        AdjList[v].push_back(make_pair(u,weight));
    }
    cout<<endl;
    for (int i = 0; i < vertex; i++)
    {
        cout<<i<<"->";
        for(int j = 0; j < AdjList[i].size(); j++)
            cout<<"("<<AdjList[i][j].first<<","<<AdjList[i][j].second<<") ";
        cout<<endl;
    }

    return 0;
}