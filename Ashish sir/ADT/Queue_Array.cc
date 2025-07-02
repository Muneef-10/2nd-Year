#include<iostream>
using namespace std;
typedef struct Queue
{
    int front;
    int rear;
    int capacity;
    int *array;
} queue;
queue* createqueue(int cap)
{
    queue* q=(queue *)malloc(sizeof(queue));
    q->front=-1;
    q->rear=-1;
    q->capacity=cap;
    q->array=(int*)malloc(sizeof(int)*q->capacity);
}
void enqueue(queue* q,int val)
{
    if(q->rear==(q->capacity-1)) cout<<"Queue is full\n";
    else{
    if(q->front==-1) q->front=0;
    (q->rear)++;
    q->array[q->rear]=val;
    }
}
int dequeue(queue* q)
{
    if(q->front>q->rear) cout<<"Queue is empty\n";
    else{
    int v=q->array[q->front];
    (q->front)++;
    return v;
    }
}
void display(queue* q)
{
    if(q->front==-1) cout<<"Queue is empty\n";
    else
    {
        for (int i = q->front; i <=q->rear; i++)
        {
            cout<<q->array[i]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter size of array of queue: ";
    cin>>n;
    queue *q=createqueue(n);
    enqueue(q,10);
    enqueue(q,15);
    enqueue(q,20);
    enqueue(q,25);
    enqueue(q,30);
    enqueue(q,35);
    display(q);

    cout<<"Deleted element: "<<dequeue(q)<<endl;
    display(q);

    cout<<"Deleted element: "<<dequeue(q)<<endl;
    display(q);
    return 0;
}