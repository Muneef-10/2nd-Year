/*Design an algorithm and a program to implement two stacks by using only one array i.e. both the stacks should use the same array for push and pop operation.
Array should be divided in such a manner that space should be efficiently used if one stack contains very large number of elements and other one contains only
few elements.

Input Format: 
First line will take size of stack.
Second line will ask user whether it wants to push/pop in stack1 or stack2, then accordingly perform operation.*/

#include<stdio.h>

void push1(int *top1,int *top2,int st[],int n)
{
    if((*top2)-(*top1)==1) printf("Stack 1 is full\n");
    else
    {
        int x;
        printf("Enter element in stack 1: ");
        scanf("%d",&x);
        (*top1)++;
        st[*top1]=x;
    }
}

void push2(int *top1,int *top2,int st[],int n)
{
    if((*top2)-(*top1)==1) printf("Stack 2 is full\n");
    else
    {
        int x;
        printf("Enter element in stack 2: ");
        scanf("%d",&x);
        (*top2)--;
        st[*top2]=x;
    }
}

void pop1(int *top1,int st[])
{
    if((*top1)==-1) printf("Stack 1 is empty\n");
    else
    {
        printf("Deleted element from stack 1 is: %d\n",st[*top1]);
        (*top1)--;
    }
}

void pop2(int *top2,int st[],int n)
{
    if((*top2)==n) printf("Stack 1 is empty\n");
    else
    {
        printf("Deleted element from stack 2 is: %d\n",st[*top2]);
        (*top2)++;
    }
}

void display(int top1, int top2, int st[],int n)
{
    printf("Stack 1:  ");
    for (int i = 0; i <=top1; i++)
    {
        printf("%d ",st[i]);
    }

    printf("\nStack 2:  ");
    for (int i = n-1; i>=top2; i--)
    {
        printf("%d ",st[i]);
    }
    printf("\n");
    
}

void main()
{
    int top1=-1,n,a;
    printf("Enter the size of the stack: ");
    scanf("%d",&n);
    int st[n],top2=n;
    do
    {
        printf("\nPress [1] for push in stack 1\n");
        printf("Press [2] for pop in stack 1\n");
        printf("Press [3] for push in stack 2\n");
        printf("Press [4] for pop in stack 2\n");
        printf("Press [5] for display\n");
        printf("Press [0] for Exit\n");
        scanf("%d",&a);
        switch(a)
        {
            case 0:
                printf("Exit..");
                break;
            case 1:
                push1(&top1,&top2,st,n);
                break;
            case 2:
                pop1(&top1,st);
                break;
            case 3:
                push2(&top1,&top2,st,n);
                break;
            case 4:
                pop2(&top2,st,n);
                break;
            case 5:
                display(top1,top2,st,n);
                break;
            default:
                printf("Try again, Invalid input");
                break;
        }
    } while (a!=0);
       
}