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
typedef struct Node
{
    int src;
    int dst;
    int wt;
    struct Node *next;
}node;
graph* create(int val)
{
    graph *tmp=(graph *)malloc(sizeof(graph));
    tmp->v=val;
    tmp->arr=(edge**)malloc(val*sizeof(edge*));
    for (int i = 0; i < val; i++)
    {
        tmp->arr[i]=NULL;
    }
    return tmp;
}
void AddEdge(graph *g,int s,int d,int w)
{
    edge *tmp=(edge*)malloc(sizeof(edge));
    tmp->dst=d;
    tmp->wt=w;
    tmp->next=g->arr[s];
    g->arr[s]=tmp;
}
node *createNode(int s,int d,int w)
{
    node *tmp=(node*)malloc(sizeof(node));
    tmp->src=s;
    tmp->dst=d;
    tmp->wt=w;
    tmp->next=NULL;
    return tmp;
}
void display(graph *g)
{
    for (int i = 0; i < g->v; i++)
    {
        printf("Vertex: %d",i);
        edge *curr=g->arr[i];
        while (curr!=NULL)
        {
            printf("-> %d (weight %d)",curr->dst,curr->wt);
            curr=curr->next;
        }
        printf("\n");
        
    }
    
}
void displayList(node *head)
{
    while(head!=NULL)
    {
        printf("%d->%d (%d) ,",head->src,head->dst,head->wt);
        head=head->next;
    }
    printf("\n");
}
void insertList(node **head,int s,int d,int w)
{
    node *tmp=createNode(s,d,w);
    node *dummy=createNode(-1,-1,-1);
    dummy->next=(*head);
    node *curr=dummy;
    while(curr->next!=NULL && curr->next->wt<w)
    {
        curr=curr->next;
    }
    tmp->next=curr->next;
    curr->next=tmp;
    (*head)=dummy->next;
    free(dummy);
}
void createList(graph *g,node **head)
{
    for (int i = 0; i < g->v; i++)
    {
        edge *curr=g->arr[i];
        while(curr!=NULL)
        {
            insertList(head,i,curr->dst,curr->wt);
            curr=curr->next;
        }
    }
    
}
int find(int djset[],int val)
{
    if(djset[val]==val)
    return val;
    return djset[val]=find(djset,djset[val]);
}
void Union(int djset[],int rank[],int s,int d)
{
    if(rank[s]>rank[d])
    {
        djset[d]=s;
    }
    else if(rank[s]<rank[d])
    {
        djset[s]=d;
    }
    else
    {
        djset[d]=s;
        rank[s]++;
    }
}
void krushkal(graph *MST,node *head,int djset[],int rank[])
{
    while(head!=NULL)
    {
        if(find(djset,djset[head->src])!=djset[head->dst])
        {
            AddEdge(MST,head->src,head->dst,head->wt);
            Union(djset,rank,find(djset,djset[head->src]),find(djset,djset[head->dst]));
        }
        head=head->next;
    }
}
void main()
{
    graph *Graph=NULL;
    graph *MST=NULL;
    node *head=NULL;
    int v,choice;
    printf("Enter number of vertex: ");
    scanf("%d",&v);
    Graph=create(v);
    do
    {
        printf("Press [1] to add edge\n");
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
            printf("Enter source destination weight");
            scanf("%d%d%d",&s,&d,&w);
            AddEdge(Graph,s,d,w);
            break;
        }
        default:
            printf("Invalid input ,try again..\n");
            break;
        }
    } while (choice !=0);

    display(Graph);
    createList(Graph,&head);
    displayList(head);
    int djset[v];
    int rank [v];
    for (int i = 0; i < v; i++)
    {
        djset[i]=i;
        rank[i]=0;
    }
    MST=create(v);
    krushkal(MST,head,djset,rank);
    printf("Minimun spanning tree:\n");
    display(MST);
    
    

}