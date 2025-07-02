//implementation queue using stack.

#include<stdio.h>
#define SIZE 5

void push(int *top,int s[],int val)
{
    (*top)++;
    s[*top]=val;
}

int pop(int s[],int *top)
{
    if((*top)==-1) 
    {
        printf("Queue is empty\n");
        return -1;
    }
    int x=s[*top];
    (*top)--;
    return x;
}

void enqueue(int* top1,int* top2,int s1[],int s2[],int val)
{
    if(*top1==SIZE - 1)
        printf("\nQueue is full\n");
    while(*top1!=-1)
    {
        push(top2,s2,pop(s1,top1));
    }
    push(top1,s1,val);

    while(*top2!=-1)
    {
        push(top1,s1,pop(s2,top2));
    } 

}

void dequeue(int *top1,int s1[])
{
    printf("Deleted value is: %d\n",pop(s1,top1));
}

void display(int s[], int top)
{
    for (int i = 0; i <=top; i++)
    {
        printf("%d ",s[i]);
    }
    printf("\n");
    
}

void main()
{
    int  top1=-1,top2=-1,s1[SIZE],s2[SIZE];
    enqueue(&top1,&top2,s1,s2,10);
    enqueue(&top1,&top2,s1,s2,15);
    enqueue(&top1,&top2,s1,s2,20);
    enqueue(&top1,&top2,s1,s2,25);
    display(s1,top1);

    dequeue(&top1,s1);
    display(s1,top1);
    
    dequeue(&top1,s1);
    display(s1,top1);
    
    enqueue(&top1,&top2,s1,s2,30);
    enqueue(&top1,&top2,s1,s2,35);
    enqueue(&top1,&top2,s1,s2,40);
    display(s1,top1);

    dequeue(&top1,s1);
    dequeue(&top1,s1);
    dequeue(&top1,s1);
    dequeue(&top1,s1);
    dequeue(&top1,s1);
    dequeue(&top1,s1);

}