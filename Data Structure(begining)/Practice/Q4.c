#include<stdio.h>
int push(int top,int st[],int n,int v)
{
    if(top==n-1)
    {
        printf("Stack is full  ");
        
    }
    else 
    {
        top++;
        st[top]=v;
    }
    return top;
}
void pop(int*top,int st[])
{
    if(*top==-1) printf("Stack is empty\n");
    else
    {
        printf("\nDeleted number: %d\n",st[*top]);
        (*top)--;
    }
}

void peek(int*top,int st[])
{
    if(*top==-1) printf("Stack is empty\n");
    else
    {
        printf("\nTopmost element: %d\n",st[*top]);
    }
}
void display(int top,int st[])
{
    if(top==-1) printf("Stack is empty\n");
    else
    {
    printf("Stack elements are:\n");
    for (int i = top; i>=0; i--)
    {
        printf("%d ",st[i]);
    }
    }
}
void main()
{
    int n;
        printf("Enter size of stack: ");
        scanf("%d",&n);
        int st[n],top=-1;
    int a;
    do
    {
        printf("\nPress [1] for push\nPress [2] for pop\nPress [3] for peek/top\nPress [4] for display\nPress [0] for exit\n");
        scanf("%d", &a);
        switch(a)
    {
        case 0:
            printf("Exiting...");
            break;
        case 1:
            
            top=push(top,st,n,1);
            top=push(top,st,n,2);
            top=push(top,st,n,3);
            top=push(top,st,n,4);
            top=push(top,st,n,5);
            break;
        case 2:
            pop(&top,st);
            break;
        case 3:
            peek(&top,st);
            break;
        case 4:
            display(top,st);
            break;
        default:
            printf("Invalid input,Try again");
    }
    } while (a!=0);
    

}