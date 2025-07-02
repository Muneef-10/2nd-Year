#include<iostream>
using namespace std;
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
node *createnode(int val)
{
    node* tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    return tmp;
}
void enqueue(queue **q,int val)
{
    node *tmp=createnode(val);
    if((*q)->front==NULL && (*q)->rear==NULL){
    (*q)->front=tmp;
    (*q)->rear=tmp;
    }
    else
    {
        (*q)->rear->next=tmp;
        (*q)->rear=tmp;
    }
}
int dequeue(queue *q)
{
    if(q->front==NULL && q->rear==NULL) 
    {
        cout<<"Queue is empty"<<endl;
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
void display(queue *q)
{
    node* tmp=q->front;
    while(tmp!=NULL)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}
int main()
{
    queue *q=initializequeue();;
    
    enqueue(&q,10);
    enqueue(&q,15);
    enqueue(&q,20);
    enqueue(&q,25);
    enqueue(&q,30);
    enqueue(&q,35);
    display(q);

    cout<<"Deleted element: "<<dequeue(q)<<endl;
    display(q);
    cout<<"Deleted element: "<<dequeue(q)<<endl;
    display(q);
    
    return 0;
}
