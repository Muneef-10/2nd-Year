#include<bits/stdc++.h>
using namespace std;
bool Detect(int node,vector<int> AdjList[], vector<int> &visited, vector<int> &recStack)
{
    visited[node]=1;
    recStack[node]=1;
    for (int i = 0; i < AdjList[node].size(); i++)
    {
        if(recStack[AdjList[node][i]])  return true;
        if(!visited[AdjList[node][i]] && Detect(AdjList[node][i],AdjList,visited,recStack))return true;
    }
    recStack[node]=0;
    return false;
}
int main()
{
    int vertex,edges;
    cout<<"Enter number of vertices and edges: ";
    cin>>vertex>>edges;
    vector<int> AdjList[vertex];
    int u,v;
    cout<<"Enter edges from - to"<<endl;
    for (int i = 0; i < edges; i++)
    {
        cin>>u>>v;
        AdjList[u].push_back(v);
        // AdjList[v].push_back(u);
    }

    for (int i = 0; i < vertex; i++)
    {
        cout<<i<<"->";
        for (int j = 0; j < AdjList[i].size(); j++)
        {
            cout<<AdjList[i][j]<<" ";
        }
        cout<<endl;
        
    }
    vector<int> visited(vertex,0);
    vector<int> recStack(vertex,0);
    for (int i = 0; i < vertex ; i++)
    {
        if(!visited[i] && Detect(i,AdjList,visited,recStack))
        {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    
    return 0;
}