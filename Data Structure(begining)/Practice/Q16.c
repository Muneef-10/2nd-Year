//implementation stack using queue.

#include<stdio.h>
#define SIZE 5

void enqueue(int q[],int *f,int*r,int val)
{
    if(*f==-1) *f=0;
    (*r)++;
    q[*r]=val;
}

int dequeue(int q[],int *f,int *r)
{
    int n=q[*f];
    if(*f==*r) *r=*f=-1;
    else (*f)++;
    return n;
}
void push(int q1[],int q2[],int *f1, int *f2, int *r1, int*r2,int val)
{
    if(*r1==SIZE-1) printf("Stack is full\n");
    else
    {
        enqueue(q2,f2,r2,val);
        while(*f1!=-1) 
        {
            enqueue(q2,f2,r2,dequeue(q1,f1,r1));
        }
        for (int i = *f2; i <=*r2; i++)
        {
            q1[i]=q2[i];
        }
        

        int a=*f1;
        *f1=*f2;
        *f2=a;

        int b=*r1;
        *r1=*r2;
        *r2=b;
    }
}

void pop(int q1[],int *f1,int *r1)
{
    if(*f1==-1) printf("Stack is empty\n");
    else
    printf("Deleted value is: %d\n",dequeue(q1,f1,r1));
}

void display(int q1[],int f1,int r1)
{
    for (int i = r1; i >=f1;i--)
    {
        printf("%d ",q1[i]);
    }
    printf("\n");
    
}
void main()
{
    int q1[SIZE],q2[SIZE],f1=-1,f2=-1,r1=-1,r2=-1;
    push(q1,q2,&f1,&f2,&r1,&r2,100);
    push(q1,q2,&f1,&f2,&r1,&r2,15);
    push(q1,q2,&f1,&f2,&r1,&r2,20);
    push(q1,q2,&f1,&f2,&r1,&r2,25);
    display(q1,f1,r1);
    pop(q1,&f1,&r1);
    pop(q1,&f1,&r1);
    display(q1,f1,r1);
}