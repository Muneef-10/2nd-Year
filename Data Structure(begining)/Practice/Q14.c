/*Design an algorithm and write a program to implement Deque i.e. double ended queue. Double ended queue is a queue in which insertion and deletion can be done
from both ends of the queue. The program should implement following operations:
a) insertFront() - insert an element at the front of Deque
b)insertEnd() - insert an element at the end of Deque
c) deleteFront() - delete an element from the front of Deque
d) deleteEnd() - delete an element from the end of Deque
e) isEmpty() - checks whether Deque is empty or not
f)isFull() - checks whether Deque is full or not
g) printFront() - print Deque from front
h) printEnd() - print Deque from end*/

#include<stdio.h>
#include<stdbool.h>

void insertFront(int q[], int n, int *f, int *r)
{
    if((*r+1)%n==*f) printf("Queue is full\n");
    else
    {
        int a;
        printf("Enter element from front side: ");
        scanf("%d",&a);
        if(*f==-1 && *r==-1) *f=*r=0;
        else if(*f==0) *f=n-1;
        else *f=*f-1;
        q[*f]=a;
    }
}

void insertEnd(int q[], int n, int *f, int *r)
{
    if((*r+1)%n==*f) printf("Queue is full\n");
    else
    {
        int a;
        printf("Enter element from rear side: ");
        scanf("%d",&a);
        if(*f==-1 && *r==-1) *f=*r=0;
        else *r=(*r+1)%n;
        q[*r]=a;
    }
}

void deleteFront(int q[], int n, int *f, int *r)
{
    if(*f==-1) printf("Queue is empty\n");
    else
    {
        printf("Deleted element from front side is: %d\n",q[*f]);
        if(*f==*r) *f=*r=-1;
        else *f=(*f+1)%n;
    }
}

void deleteEnd(int q[], int n, int *f, int *r)
{
    if(*f==-1) printf("Queue is empty\n");
    else
    {
        printf("Deleted element from rear side is: %d\n",q[*r]);
        if(*f==*r) *f=*r=-1;
        else 
        {
            if(*r==0) *r=n-1;
            else *r=*r-1;
        }
    }
}

bool IsEmpty(int f)
{
    return f==-1;
}

bool IsFull(int f, int r,int n)
{
    if((r+1)%n==f) return true;
    else return false;
}

void printFront(int q[], int n, int f, int r)
{
    for (int i = f; i!=r; i=(i+1)%n)
    {
        printf("%d ",q[i]);
        f=(f+1)%n;
    }
    printf("%d\n",q[r]);
}

void printEnd(int q[], int n, int f, int r)
{
    int i=r;
    while(i!=f)
    {
        printf("%d ",q[i]);
        if(i==0) i=n-1;
        else i--;
    }
    printf("%d\n",q[f]);
}

void main()
{
    int n,a;
    printf("Enter the size of queue: ");
    scanf("%d",&n);
    int q[n],f=-1,r=-1;
    do
    {
        printf("Press [1] for insert in front\n");
        printf("Press [2] for insert in rear\n");
        printf("Press [3] for dequeue from front\n");
        printf("Press [4] for dequeue from rear\n");
        printf("Press [5] to check queue is empty or not\n");
        printf("Press [6] to check queue is full or not\n");
        printf("Press [7] for display from front\n");
        printf("Press [8] for display from rear\n");
        printf("Press [0] for exit\n");
        scanf("%d",&a);
        switch(a)
        {
            case 0:
                printf("Exit..");
                break;
            case 1:
                insertFront(q,n,&f,&r);
                break;
            case 2:
                insertEnd(q,n,&f,&r);
                break;
            case 3:
                deleteFront(q,n,&f,&r);
                break;
            case 4:
                deleteEnd(q,n,&f,&r);
                break;
            case 5:
                if(IsEmpty(f)) printf("Queue is empty\n");
                else printf("Queue is not empty\n");
                break;
            case 6:
                if(IsFull(f,r,n)) printf("Queue is full\n");
                else printf("Queue is not full\n");
                break;
            case 7:
                printFront(q,n,f,r);
                break;
            case 8:
                printEnd(q,n,f,r);
                break;
            default:
                printf("Invalid input,Try again...\n");
        }
    } while (a!=0);
    
}