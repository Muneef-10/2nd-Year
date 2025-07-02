#include<bits/stdc++.h>
using namespace std;

int Prims(vector<vector<int>>AdjList[] , int vertex, vector<int> &parent)
{
    vector<int> IsMst(vertex,0);

    priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    //wt,node,parent
    pq.push({0,{0,-1}});
    int cost=0;

    while(!pq.empty())
    {
        int wt=pq.top().first;
        int node=pq.top().second.first;
        int par=pq.top().second.second;
        pq.pop();

        if(!IsMst[node])
        {
            IsMst[node]=1;
            cost+=wt;
            parent[node]=par;
            
            for (int i = 0; i < AdjList[node].size(); i++)
            {
                if(!IsMst[AdjList[node][i][1]])
                {
                    pq.push({AdjList[node][i][0],{AdjList[node][i][1],node}});
                }
            }
        }

    } 
    return cost;
}
int main()
{
    int vertex,edge;
    cout<<"Enter number of vertices and edges: ";
    cin>>vertex>>edge;
    vector<vector<int>> AdjList[vertex];

    int u,v,w;
    cout<<"Enter edge: from to weight:"<<endl;
    for (int i = 0; i < edge; i++)
    {
        cin>>u>>v>>w;
        AdjList[u].push_back({w,v});
        AdjList[v].push_back({w,u});
    }

    vector<int> parent(vertex);
    for (int i = 0; i < vertex; i++)
        parent[i]=i;
    
    int cost=Prims(AdjList,vertex,parent);
    
    for (int i = 1; i < parent.size(); i++)
    {
        cout<<parent[i]<<"->"<<i<<endl;
    }
    cout<<"Cost: "<<cost;
    return 0;
}