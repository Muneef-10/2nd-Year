#include<bits/stdc++.h>
using namespace std;
bool Bipartite(vector<int> AdjList[],int vertex)
{
    vector<int> color(vertex,-1);
    queue<int> q;
    for(int i=0; i<vertex ;i++)
    {
        if(color[i]==-1)
        {
            q.push(i);
            color[i]=0;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                for(int j=0; j<AdjList[node].size(); j++)
                {
                    if(color[AdjList[node][j]]==-1)
                    {
                        q.push(AdjList[node][j]);
                        color[AdjList[node][j]]=(1+color[node])%2;
                    }

                    else if(color[AdjList[node][j]] == color[node])
                    {
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
    
    if(Bipartite(AdjList,vertex)) cout<<"Yes Bipartite";
    else cout<<"Not Bipartite";
    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;
    return 0;
}