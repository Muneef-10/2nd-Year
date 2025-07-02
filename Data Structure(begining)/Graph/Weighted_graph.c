#include<stdio.h>
#include<stdlib.h>
typedef struct Edge
{
    int dst;
    int wt;
    struct Edge *next;
}edge;
typedef struct Vertex
{
    int src;
    edge *edge;
    struct Vertex* next;
}vertex;
void create(vertex **graph,int val)
{
    vertex *tmp=(vertex*)malloc(sizeof(vertex));
    tmp->src=val;
    tmp->edge=NULL;
    tmp->next=(*graph);
    (*graph)=tmp;
}
void AddEdge(vertex *graph,int s,int d,int w)
{
    while(graph!=NULL)
    {
        if(graph->src==s) break;
        graph=graph->next;
    }
    if(graph==NULL)
    {
        printf("Edge can't be add\n");
        return;
    }
    edge *tmp=(edge*)malloc(sizeof(edge));
    tmp->dst=d;
    tmp->wt=w;
    tmp->next=graph->edge;
    graph->edge=tmp;
}
void display(vertex *graph)
{
    while(graph!=NULL)
    {
        printf("Vertex: %d->",graph->src);
        edge *curr=graph->edge;
        while(curr!=NULL)
        {
            printf("%d (Weight= %d)",curr->dst,curr->wt);
            curr=curr->next;
        }
        printf("\n");
        graph=graph->next;
    }
    printf("\n");
}
void main()
{
    int v,e;
    printf("Enter no. of vertex and no. of edge:\n");
    scanf("%d%d",&v,&e);
    vertex *graph=NULL;
    for (int i = 0; i < v; i++)
    {
        create(&graph,i+1);
    }
    printf("Enter edge (source destination weight)\n");
    for (int i = 0; i < e; i++)
    {
        int s,d,w;
        scanf("%d%d%d",&s,&d,&w);
        AddEdge(graph,s,d,w);
    }
    printf("Graph: ");
    display(graph);
    
    
    
}