/*Design an algorithm and write a program to implement circular queue. Circular queue is a queue in which last position of queue is connected with first 
position of queue to make a circle. The program should implement following operations:
a) Create() - create a queue of specific size
b)EnQueue(k) - insert an element k into the queue
c) DeQueue() - delete an element from the queue
d)IsEmpty() - check if queue is empty or not
e) Front() - return front item from queue
f) Rear() - return rear item from queue*/

#include<stdio.h>
#include<stdbool.h>

bool IsEmpty(int f)
{
    return f==-1;
}

bool IsFull(int f,int r,int n)
{
    if((r+1)%n==f) return true;
    else return false;
}
void enqueue(int cq[], int n, int *f, int *r)
{
    if((*r+1)%n==*f)  printf("Queue is full\n");
    else
    {
        int a;
        printf("Enter a element: ");
        scanf("%d",&a);
        if(*f==-1 && *r==-1)  *f=*r=0;
        else (*r)=(*r+1)%n;
        cq[*r]=a;
    }
}

void dequeue(int cq[], int n, int *f, int *r)
{
    if(*f==-1) printf("Queue is empty\n");
    else
    {
        printf("Deleted element is: %d\n",cq[*f]);
        if(*f==*r) *f=*r=-1;
        else *f=(*f+1)%n;
    }
}

void display(int cq[],int n,int f,int r)
{

    for(int i=f; i!=r; i=(i+1)%n)
    {
        printf("%d ",cq[i]);
    }
    printf("%d\n",cq[r]);
}

void front(int q[],int f)
{
    printf("Front/First element in queue is: %d\n",q[f]);
}

void rear(int q[],int r)
{
    printf("Last/Rear element in queue is: %d\n",q[r]);
}
void main()
{
    int n,a,f=-1,r=-1;
    printf("Enter the size of queue: ");
    scanf("%d",&n);
    int cq[n];
    do
    {
        printf("Press [1] for enqueue\n");
        printf("Press [2] for dequeue\n");
        printf("Press [3] to check queue is empty or not\n");
        printf("Press [4] to check queue is full or not\n");
        printf("Press [5] for display queue\n");
        printf("Press [6] for display front\n");
        printf("Press [7] for display rear\n");
        printf("Press [0] for exit\n");
        scanf("%d",&a);
        switch (a)
        {
        case 0:
            printf("Exit..");
            break;
        case 1:
            enqueue(cq,n,&f,&r);
            break;
        case 2:
            dequeue(cq,n,&f,&r);
            break;
        case 3:
            if(IsEmpty(f)) printf("Queue is empty\n");
            else printf("Queue is not empty\n");
            break;
        case 4:
            if(IsFull(f,r,n)) printf("Queue is full\n");
            else printf("Queue is not full\n");
            break;
        case 5:
            display(cq,n,f,r);
            break;
        case 6:
            front(cq,f);
            break;
        case 7:
            front(cq,r);
            break;
        
        default:
            printf("Invalid input, try again..");
            break;
        }
    } while (a!=0);
    
}