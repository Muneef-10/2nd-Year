// Design an algorithm and write a program to reverse a queue.(Using stack)

#include<stdio.h>
#define SIZE 5
int top=-1;//we can also initialize 'st' here in this case becaue we know the size initialize as "int st[SIZE]"

void push(int q,int st[])
{
    top++;
    st[top]=q;
}

int pop(int st[])
{
    int a=st[top];
    top--;
    return a;
}

void rq(int **f,int **r,int q[],int st[])
{
    for (int i = (**f); i <=(**r); i++)
    {
        push(q[i],st);
    }

    for (int i = (**f); i <=(**r); i++)
    {
        q[i]=pop(st);
    }
}

void enqueue(int *f,int *r,int q[])
{
    if((*r)==SIZE-1) printf("Queue is full\n");
    else
    {
        int x;
        printf("Enter element: ");
        scanf("%d",&x);
        if((*f)==-1) (*f)=0;
        (*r)++;
        q[*r]=x;
    }
}

void display(int *f,int *r,int q[],int st[])
{
    if((*f)==-1) printf("Queue is empty\n");
    else{   
    printf("Normal queue: ");
    for (int i = (*f); i <=(*r); i++)
    {
        printf("%d ",q[i]);
    }

    rq(&f,&r,q,st);

    printf("\nReversed queue: ");
    for (int i = (*f); i <=(*r); i++)
    {
        printf("%d ",q[i]);
    }
    }
}

void main()
{
    int f=-1,r=-1,a,q[SIZE],st[SIZE];
    do
    {
        printf("\nPress [1] for enqueue:\n");
        printf("Press [2] for display:\n");
        printf("Press [3] for Exit:\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                enqueue(&f,&r,q);
                break;
            case 2:
                display(&f,&r,q,st);
                break;
            case 3:
                printf("Exit..");
                break;
            default:
                printf("Try again, Invalid input\n");
            
        }
    }while(a!=3);
}