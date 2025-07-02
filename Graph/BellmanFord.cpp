#include<bits/stdc++.h>
using namespace std;
vector<int> Bellman(int vertex,vector<vector<int>> &edges,int src)
{
    vector<int> dist(vertex,1e5);
    dist[src]=0;
    int  es=edges.size();
    
    for (int i = 0; i < vertex-1; i++)
    {
        for (int j = 0; j <es; j++)
        {
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];


            if(dist[u]!=1e5 && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
        
    }


    for (int j = 0; j < es; j++)
    {
        int u=edges[j][0];
        int v=edges[j][1];
        int w=edges[j][2];


        if(dist[u]!=1e5 && dist[u] + w < dist[v])
        {
            vector<int> ans;
            ans.push_back(-1);
            return ans;
        }
    }
    
    return dist;

}
int main()
{
    int vertex,e;
    cout<<"Enter number of vertices and edges:"<<endl;
    cin>>vertex>>e;
    vector<vector<int>> edges(e,vector<int>(3));
    int u,v,w;
    cout<<"Enter in form of: from to weight"<<endl;
    for (int i = 0; i < e; i++)
    {
        cin>>u>>v>>w;
        edges[i][0]=u;
        edges[i][1]=v;
        edges[i][2]=w;
        edges.push_back({v, u, w});
    }
    int src;
    cout<<"Enter source: ";
    cin>>src;

    vector<int> dist = Bellman(vertex,edges,src);

    if(dist.size()==1 && dist[0]==-1)
    {
        cout<<"Negative cycle detect"<<endl;
        return 0;
    }

    for (int i = 0; i < dist.size(); i++)
    {
        if(dist[i]==1e5)
            cout<<src<<"->"<<i<<" "<<"Unreachable"<<endl;
        else
            cout<<src<<"->"<<i<<" "<<dist[i]<<"(weight)"<<endl;
    }
    
    
    return 0;
}