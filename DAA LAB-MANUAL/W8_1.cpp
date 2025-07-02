#include<bits/stdc++.h>
using namespace std;
int Prims(vector<vector<int>> AdjList[], int vertex)
{
    vector<bool> IsMst(vertex,0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // wt,node;
    pq.push({0,0});
    int cost = 0;
    while (!pq.empty())
    {
        int wt=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        
        if(!IsMst[node])
        {
            IsMst[node]=1;
            cost+=wt;
            for (int i = 0; i < AdjList[node].size(); i++)
            {
                if(!IsMst[AdjList[node][i][0]])
                    pq.push({AdjList[node][i][1],AdjList[node][i][0]});
            }
            
        }
    }
    return cost;
    
}
int main()
{
    int vertex,edge;
    cout<<"Enter number of vertices and edges:\n";
    cin>>vertex>>edge;
    vector<vector<int>> AdjList[vertex];

    int u,v,w;
    cout<<"Enter edges: from to weight"<<endl;
    for (int i = 0; i < edge; i++)
    {
        cin>>u>>v>>w;
        AdjList[u].push_back({v,w});
        AdjList[v].push_back({u,w});
    }

    int cost=Prims(AdjList,vertex);
    cout<<"Minimum cost of making road is: "<<cost;
    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;  
    return 0;
}