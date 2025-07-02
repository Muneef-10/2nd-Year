#include<stdio.h>
#include<stdlib.h>
typedef struct Edge
{
    int dst;
    int wt;
    struct Edge *next;
}edge;
typedef struct graph
{
    int v;
    edge **arr;
}graph;
graph *create(int v)
{
    graph *tmp=(graph*)malloc(sizeof(graph));
    tmp->v=v;
    tmp->arr=(edge **)malloc(v*sizeof(edge*));
    for (int i = 0; i < v; i++)
    {
        tmp->arr[i]=NULL;
    }
    return tmp;
}
void AddEdge(graph *g,int s,int d,int w)
{
    edge* tmp=(edge*)malloc(sizeof(edge));
    tmp->dst=d;
    tmp->wt=w;
    tmp->next=g->arr[s];
    g->arr[s]=tmp;
}
void dfs(graph *g,int s,int visited[])
{
    printf("%d -> ",s);
    visited[s]=1;
    edge *curr=g->arr[s];
    while(curr!=NULL)
    {
        if(!visited[curr->dst])
            dfs(g,curr->dst,visited);
        curr=curr->next;
    }
}
void main()
{
    int v,choice;
    printf("Enter number of vertes: ");
    scanf("%d",&v);
    graph *Graph=NULL;
    Graph=create(v);
    do
    {
        printf("Press [1] to add edge\n");
        printf("Press [2] to apply dfs\n");
        printf("Press [0] to exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 0:
            printf("Exit..\n");
            break;
        case 1:
        {
            int s,d,w;
            printf("Enter edge (source destination weight)\n");
            scanf("%d%d%d",&s,&d,&w);
            AddEdge(Graph,s,d,w);
            break;
        }
        case 2:
        {
            int s;
            printf("Enter source: ");
            scanf("%d",&s);
            int visited[v];
            for (int i = 0; i < v; i++)
            {
                visited[i]=0;
            }
            printf("DFS:\n");
            dfs(Graph,s,visited);
            printf("End\n");
            for (int i = 0; i < v; i++)
            {
                if(!visited[i])
                {
                    dfs(Graph,i,visited);
                    printf("End\n");
                }
            }          
        }
        break;
        
        default:
            printf("Invalid input,try again..\n");
            break;
        }

    } while (choice !=0);
    
}