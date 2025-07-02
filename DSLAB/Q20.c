#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct Node 
{
    int data;
    struct Node *next;
}node;
typedef struct Queue
{
    node* front;
    node* rear;
}queue;
queue* initializequeue()
{
    queue *q=(queue*)malloc(sizeof(queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}
node *createnode()
{
    int val;
    printf("Enter element: ");
    scanf("%d",&val);
    node* tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    return tmp;
}
void enqueue(queue **q)
{
    node *tmp=createnode();
    (*q)->rear->next=tmp;
    (*q)->rear=tmp;
}
int dequeue(queue *q)
{
    if(q->front==NULL && q->rear==NULL) 
    {
        printf("Queue is empty\n");
        return 0;
    }
    else{
        int v=q->front->data;
        node* tmp=q->front;
        q->front=tmp->next;
        tmp->next=NULL;
        free(tmp);
        return v;
    }
}
bool isempty(queue *q)
{
    return q->front==NULL;
}
void size(queue *q)
{
    node *tmp=q->front;
    int c=0;
    while(tmp!=NULL)
    {
        c++;
        tmp=tmp->next;
    }
    printf("Size of queue is: %d\n",c);
}
void display(queue *q)
{
    node* tmp=q->front;
    while(tmp!=NULL)
    {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}
int main()
{
    int a;
    queue *q=initializequeue();
    do
    {
        printf("Press [1] for create a queue: \n");
        printf("Press [2] for enqueue: \n");
        printf("Press [3] for dequeue: \n");
        printf("Press [4] to check queue is empty or not: \n");
        printf("Press [5] to check size of queue: \n");
        printf("Press [0] for exit: \n");
        scanf("%d",&a);
        switch (a)
        {
        case 0:
            printf("Exit..\n");
            break;
        case 1:
            q->rear=q->front=createnode();
            break;
        case 2:
            enqueue(&q);
            display(q);
            break;
        case 3:
            dequeue(q);
            display(q);
            break;
        case 4:
            if(isempty(q)) printf("Queue is empty\n");
            else printf("Queue is not empty\n");
            break;
        case 5:
            size(q);
            break;
        
        default:
            break;
        }
    } while (a!=0);
    
    
    return 0;
}
