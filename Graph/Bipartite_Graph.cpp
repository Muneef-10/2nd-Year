#include<bits/stdc++.h>
using namespace std;
bool BPG(int v,vector<int> AdjList[])
{
    queue<int> q;
    vector<int> color(v,-1);
    for (int j = 0; j < v; j++)
    {
        if(color[j]==-1)
        {
            q.push(j);
            color[j]=0;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                for (int i = 0; i < AdjList[node].size(); i++)
                {
                    if(color[AdjList[node][i]]==-1)
                    {
                        q.push(AdjList[node][i]);
                        color[AdjList[node][i]]=(color[node]+1)%2;
                    }
                    else
                    {
                        if(color[node]==color[AdjList[node][i]])
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int main()
{
    int vertex,edges;
    cout<<"Enter number of vertices and edges\n";
    cin>>vertex>>edges;
    vector<int> AdjList[vertex];
    int u,v;
    cout<<"Enter edges\n";
    for (int i = 0; i < edges; i++)
    {
        cin>>u>>v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    if(BPG(vertex,AdjList)) cout<<"YES";
    else cout<<"No";

    return 0;
}