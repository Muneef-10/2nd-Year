//implementation queue using stack.

#include<stdio.h>
#define SIZE 5

void push(int s[],int *top, int val)
{
    if(*top==SIZE-1) printf("Queue is full\n");
    else
    {
        (*top)++;
        s[*top]=val;
    }
}

int pop(int *top,int s[])
{
    int x=0;
    if(*top==-1) 
    {
        printf("Queue is empty\n");
        return -1;
    }
    else 
    {
        x=s[*top];
        (*top)--;
        return x;
    }
    
}

void enqueue(int s1[],int *top1, int val)
{
    push(s1,top1,val);
}

void dequeue(int s1[],int s2[], int*top1,int *top2)
{
    if(*top1==-1 && *top2==-1) printf("Queue is empty\n");
    else{
    while(*top1!=-1)
    {
        push(s2,top2,pop(top1,s1));
    }
    printf("Deleted element is: %d\n",pop(top2,s2));

    while(*top2!=-1)
    {
        push(s1,top1,pop(top2,s2));
    }
    }
}

void display(int s[], int top)
{
    for (int i = 0; i <=top; i++)
    {
        printf("%d ",s[i]);
    }
    printf("\n");
    
}

int main()
{
    int top1=-1,top2=-1,s1[SIZE],s2[SIZE];
    enqueue(s1,&top1,10);
    enqueue(s1,&top1,15);
    enqueue(s1,&top1,20);
    enqueue(s1,&top1,25);
    display(s1,top1);

    dequeue(s1,s2,&top1,&top2);
    dequeue(s1,s2,&top1,&top2);
    enqueue(s1,&top1,30);
    enqueue(s1,&top1,35);
    enqueue(s1,&top1,40);
    display(s1,top1);

    return 0;
}
