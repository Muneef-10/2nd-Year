#include<bits/stdc++.h>
using namespace std;
void DFS(int node,vector<int> AdjList[], vector<int> &visited,stack<int> &s)
{
    visited[node]=1;
    for(int i=0;i<AdjList[node].size();i++)
    {
        if(visited[AdjList[node][i]]==0)
        {
            DFS(AdjList[node][i],AdjList,visited,s);
        }
    }
    s.push(node);
}
int main()
{
    int vertex,edge;
    cout<<"Enter number of vertices & edges:"<<endl;
    cin>>vertex>>edge;
    int u,v;
    vector<int> AdjList[vertex];
    cout<<"Enter edges from - to"<<endl;
    for(int i=0;i<edge;i++)
    {
        cin>>u>>v;
        AdjList[u].push_back(v); //DAG
    }

    vector<int> visited(vertex,0),ans;
    stack<int> s;
    for(int i=0;i<vertex;i++)
    {
        if(!visited[i])
            DFS(i,AdjList,visited,s);
    }
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    for(int i=0;i<vertex;i++)
        cout<<ans[i]<<" ";
    return 0;
}