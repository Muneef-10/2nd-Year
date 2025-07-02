#include<stdio.h>

void push(int st[],int *top,int val)
{
    (*top)++;
    st[*top]=val;
}
int pop(int st[],int *top)
{
    int d=st[*top];
    (*top)--;
    return d;
}
void enqueue(int st1[],int st2[],int n,int *top1,int *top2)
{
    if(*top1==n-1) printf("Queue is full\n");
    else
    {
        int a;
        printf("Enter element: ");
        scanf("%d",&a);
        while(*top1!=-1)
        {
            push(st2,top2,pop(st1,top1));
        }
        push(st1,top1,a);
        while(*top2!=-1)
        {
            push(st1,top1,pop(st2,top2));
        }
    }
}
void dequeue(int st1[],int *top1)
{
    if(*top1==-1) printf("Queue is empty\n");
    else printf("Deleted element is: %d\n",pop(st1,top1));
}
void display(int st1[],int n,int*top1)
{
    for (int i = *top1; i >=0; i--)
    {
        printf("%d ",st1[i]);
    }
    printf("\n");
}
void main()
{
    int top1=-1,top2=-1,n,a=0;
    printf("Enter size of an array: ");
    scanf("%d",&n);
    int st1[n],st2[n];
    do
    {
        printf("Press [1] to enqueue\n");
        printf("Press [2] to dequeue\n");
        printf("Press [3] to display queue\n");
        printf("Press [0] to exit\n");
        scanf("%d",&a);
        switch(a)
        {
            case 0:
                printf("Exit..\n");
                break;
            case 1:
                enqueue(st1,st2,n,&top1,&top2);
                break;
            case 2:
                dequeue(st1,&top1);
                break;
            case 3:
                display(st1,n,&top1);
                break;
            default:
                printf("Invalid input,try again..\n");
                break;
        }
    }while(a!=0);
}