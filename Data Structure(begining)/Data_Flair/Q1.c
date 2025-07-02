#include<stdio.h>
void push(int *top,int s,int val,int st[])
{
    if(*top==s-1) printf("Stack is full\n");
    else
    {
        printf("Enter value: ");
        scanf("%d",&val);
        (*top)++;
        st[*top]=val;
    }
}
void pop(int *top,int st[])
{
    if(*top==-1) printf("Stack is Empty\n");
    else
    {
        printf("Deleted element: %d\n",st[*top]);
        (*top)--;
    }
}
void display(int st[],int s,int top)
{
    printf("Elements of stack: \n");
    // for (int i = top; i >=0; i--)
    // {
    //     printf("\n%d",st[i]);
    // }
    for (int i = 0; i <=top; i++)
    {
        printf("%d ",st[i]);
    }
    printf("\n");
}
void main()
{
    int top=-1,n,val=0,s=0;
    printf("Enter size of stack: ");
    scanf("%d",&s);
    int st[s];
    
    do
    {
        printf("------STACK MENU------\n");
        printf("Press [1] for push:\n");
        printf("Press [2] for pop:\n");
        printf("Press [3] for display:\n");
        printf("Press [0] for exit:\n");
        printf("----------------------\n");
        scanf("%d",&n);
        switch(n)
        {
            case 0:
                printf("Exit...");
                break;
            case 1:
                push(&top,s,val,st);
                break;
            case 2:
                pop(&top,st);
                break;
            case 3:
                display(st,s,top);
                break;
            default: 
                printf("Invalid input\n");
                break;
        }
    }while(n!=0);
    
}