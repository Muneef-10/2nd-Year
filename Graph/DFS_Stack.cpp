#include<bits/stdc++.h>
using namespace std;
void DFS(int node,vector<int> &visited,vector<int> AdjList[],vector<int> &ans)
{
    stack<int> st;
    visited[node]=1;
    st.push(node);

    while(!st.empty())
    {
        node=st.top();
        st.pop();
        ans.push_back(node);
        
        for (int i = 0; i < AdjList[node].size(); i++)
        {
            if(visited[AdjList[node][i]]!=1)
            {
                visited[AdjList[node][i]]=1;
                st.push(AdjList[node][i]);
            }
        }
    }
    
}
int main()
{
    int vertex,edges,st,u,v;
    cout<<"Enter number of vertices and edges:"<<endl;
    cin>>vertex>>edges;

    vector<int> AdjList[vertex];

    cout<<"Enter edges from - to"<<endl;
    for (int i = 0; i < edges; i++)
    {
        cin>>u>>v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    vector<int> ans,visited(vertex,0);
    cout<<"Enter starting node: ";
    cin>>st;
    DFS(st,visited,AdjList,ans);


    for (int i = 0; i < vertex; i++)
    {
        cout<<i<<"->";
        for (int j = 0; j < AdjList[i].size(); j++)
        {
            cout<<AdjList[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"DFS:"<<endl;
    for (int i = 0; i < vertex; i++)
        cout<<ans[i]<<" ";
    
}