#include<bits/stdc++.h>
using namespace std;
vector<int> BFS(int v,vector<int> AdjList[])
{
    queue<int> q;
    vector<bool> visited(v,0);  
    int st;
    cout<<"Enter starting node: ";
    cin>>st;
    q.push(st);
    visited[st]=1;
    vector<int> ans;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for (int j = 0; j < AdjList[node].size(); j++)
        {
            if(visited[AdjList[node][j]]!=1)
            {
                visited[AdjList[node][j]]=1;
                q.push(AdjList[node][j]);
            }
        }
    }
    return ans;

}
int main()
{
    int vertex,edges;
    cout<<"Enter number of vertices and edges:"<<endl;
    cin>>vertex>>edges;

    vector<int> AdjList[vertex];
    
    int u,v;
    cout<<"Enter edges from - to"<<endl;
    for (int i = 0; i < edges; i++)
    {
        cin>>u>>v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    vector<int> ans=BFS(vertex,AdjList);
    
    cout<<"BFS:"<<endl;
    for (int i = 0; i < ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    
    
    return 0;
}