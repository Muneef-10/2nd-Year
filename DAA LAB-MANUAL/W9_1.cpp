#include<bits/stdc++.h>
using namespace std;
void FloydWarshall(vector<vector<int>> &AdjMat, int vertex)
{
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            for (int k = 0; k < vertex; k++)
            {
                if(AdjMat[j][i]==INT_MAX || AdjMat[i][k]==INT_MAX) continue;
                AdjMat[j][k] = min(AdjMat[j][k],AdjMat[j][i]+AdjMat[i][k]);
            }   
        }   
    }
}
int main()
{
    int vertex,edge;
    cout<<"Enter number of vertices and edges:";
    cin>>vertex>>edge;
    vector<vector<int>> AdjMat(vertex,vector<int>(vertex,INT_MAX));
    
    int u,v,w;
    cout<<"Enter edge: from to weight"<<endl;
    for (int i = 0; i < edge; i++)
    {
        cin>>u>>v>>w;
        AdjMat[u][v]=w;
    }

    for (int i = 0; i < vertex; i++)
    {
        for(int j=0;j<vertex;j++)
        {
            if(i==j)
                AdjMat[i][j]=0;
        }
    }
    
    FloydWarshall(AdjMat,vertex);

    for (int i = 0; i < vertex; i++)
    {
        if(AdjMat[i][i] < 0)
        {
            cout<<"Negative cycle detect"<<endl;
            return 0;
        }
    }
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            if(AdjMat[i][j] == INT_MAX)
                cout<<i<<"- "<<j<<"Path not exist";
            else
            cout<<i<<"-"<<j<<" "<<AdjMat[i][j]<<"  ";
        }
        cout<<endl; 
    }
    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;
    return 0;
}