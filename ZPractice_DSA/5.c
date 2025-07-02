//Implement queue using linked list.
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}node;
typedef struct Queue
{
    node *front;
    node *rear;
}queue;
queue* initialize()
{
    queue *q=(queue *)malloc(sizeof(queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}
node *createnode(int val)
{
    node *tmp=(node *)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    return tmp;
}
void enqueue(queue *q,int val)
{
    node *tmp=createnode(val);
    if(q->front==NULL && q->rear==NULL)
    {
        q->front=q->rear=tmp;
    }
    else
    {
        q->rear->next=tmp;
        q->rear=tmp;
    }
}
int dequeue(queue *q)
{
    if(q->front==NULL) printf("Empty\n");
    else
    {
        node *tmp=q->front;
        int v=tmp->data;
        q->front=q->front->next;
        tmp->next=NULL;
        free(tmp);
        return v;
    }
}
void display(queue *q)
{
    node*tmp=q->front;
    while(tmp!=NULL)
    {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}
void main()
{
    queue *q=initialize();
    enqueue(q,10);
    enqueue(q,15);
    enqueue(q,20);
    enqueue(q,25);
    enqueue(q,30);
    enqueue(q,35);
    display(q);
    printf("Deleted element: %d\n",dequeue(q));
    printf("Deleted element: %d\n",dequeue(q));
    display(q);
}