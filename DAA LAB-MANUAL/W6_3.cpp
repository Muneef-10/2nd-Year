#include<bits/stdc++.h>
using namespace std;
bool CycleExist(int src,vector<int> visited,vector<int> AdjList[])
{
    queue<pair<int,int>> q;
    q.push({src,-1});
    visited[src]=1;
    while(!q.empty())
    {
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(int i=0; i<AdjList[node].size(); i++)
        {
            if(AdjList[node][i] ==parent) continue;
            if(visited[AdjList[node][i]])
                return true;

            q.push({AdjList[node][i],node});
            visited[AdjList[node][i]]=1;
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
    }   
    
    vector<int> visited(vertex,0);
    
    for(int i=0; i<vertex; i++)
    {
        if(!visited[i] && CycleExist(i,visited,AdjList))
        {
            cout<<"Yes Cycle Exists";
            return 0;
        }
    }
    cout<<"No Cycle Exists";
    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;
    return 0;
}