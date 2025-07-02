#include<bits/stdc++.h>
using namespace std;
vector<int> Bellman(int vertex, vector<vector<int>> edges,int src,vector<int> &parent)
{
    vector<int> dist(vertex,INT_MAX);
    dist[src]=0;

    for (int i = 0; i < vertex-1; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];
            
            if(dist[u] + w < dist[v])
            {
                dist[v]=dist[u]+w;
                parent[v]=u;
            }
        }
    }
    return dist;
}
void print(int node,vector<int> parent)
{
    if(node==-1) return;
    cout<<node<<" ";
    print(parent[node],parent);
}
int main()
{
    int vertex,edge;
    cout<<"Enter number of vertex and edge:"<<endl;
    cin>>vertex>>edge;
    vector<vector<int>> edges;

    int u,v,w;
    cout<<"Enter edge from to weight"<<endl;
    for(int i=0; i<edge; i++)
    {
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
        edges.push_back({v,u,w});
    }
    int src;
    cout<<"Enter source: ";
    cin>>src;
    vector<int> parent(vertex,-1);
    vector<int> dist=Bellman(vertex,edges,src,parent);
    for (int i = 0; i < dist.size(); i++)
    {
        cout<<i<<"-"<<src<<" path ";
        print(i,parent);
        cout<<"Distance: "<<dist[i]<<endl;
    }
    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;    

    return 0;
}