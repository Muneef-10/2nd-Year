#include<bits/stdc++.h>
using namespace std;
int Max= 999;
void FloydWarshall(vector<vector<int>> &AdjMat,int vertex)
{
    for ( int i = 0; i < vertex; i++)
    {
        for(int j=0;j<vertex;j++)
        {
            if(AdjMat[i][j]==-1)
                AdjMat[i][j]=Max;
        }
    }
    
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            for (int k = 0; k < vertex; k++)
            {
                if(AdjMat[j][i]==Max || AdjMat[i][k]==Max) continue;
                AdjMat[j][k]=min(AdjMat[j][k], AdjMat[j][i]+AdjMat[i][k]);
            }
        }
    }
    
}
int main()
{
    int vertex,edge;
    cout<<"Enter number of vertices and edges: ";
    cin>>vertex>>edge;

    vector<vector<int>> AdjMat(vertex,vector<int>(vertex,-1));

    int u,v,w;
    cout<<"Enter edge in form of: from to weight"<<endl;
    for (int i = 0; i < edge; i++)
    {
        cin>>u>>v>>w;
        AdjMat[u][v]=w;
    }
    
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            if(i==j)
                AdjMat[i][j]=0;
        }
    }
    
    FloydWarshall(AdjMat,vertex);
    //if(diagonal =-1 means negative cycle present)
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            
            if(AdjMat[i][j]==Max)
                cout<<i<<"->"<<j<<"(Path not exist)";
            else
            {
                cout<<i<<"->"<<j<<" ("<<AdjMat[i][j]<<") ";
            }
        }
        cout<<endl;
    }
    
    
    return 0;
}