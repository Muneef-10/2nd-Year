#include<bits/stdc++.h>
using namespace std;
int main()
{
    int vertex,edge;
    cout<<"Enter number of vertices and edges:"<<endl;
    cin>>vertex>>edge;
    vector<int> AdjList[vertex];
    int u,v;
    cout<<"Enter edges from - to:"<<endl;
    for (int i = 0; i < edge; i++)
    {
        cin>>u>>v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    cout<<endl;
    for (int i = 0; i < vertex; i++)
    {
        cout<<i<<"->";
        for(int j = 0; j < AdjList[i].size(); j++)
            cout<<AdjList[i][j]<<" ";
        cout<<endl;
    }
    

    return 0;
}