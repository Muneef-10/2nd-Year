#include<bits/stdc++.h>
using namespace std;
bool PathExist(vector<int> AdjList[],int src,int dst,vector<int> visited)
{
    if(src==dst) return true;
    visited[src]=1;
    for(int i=0;i<AdjList[src].size();i++)
    {
        if(visited[AdjList[src][i]]==0)
        {
        if(PathExist(AdjList,AdjList[src][i],dst,visited)) return true;
        }
    }
    return false;
}
int main()
{
    int vertex,edge;
    cout<<"Enetr number of vertices and edges:"<<endl;
    cin>>vertex>>edge;
    vector<int> AdjList[vertex];
    int u,v;
    cout<<"Enter edge: from - to"<<endl;
    for (int i = 0; i < edge; i++)
    {
        cin>>u>>v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    int src,dst;
    cout<<"Enter source and destination:"<<endl;
    cin>>src>>dst;
    
    vector<int> visited(vertex,0);
    if(PathExist(AdjList,src,dst,visited)) cout<<"Yes Path Exists";
    else cout<<"No Such Path Exists";
    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;

    return 0;
}