#include<stdio.h>
int push(int top,int st[],int n, int v)
{
    if(top==n-1)
    {
        printf("Stack is full  ");
        return top;
    }
    else
    {
        top++;
        st[top]=v;
        return top;
    }
}
void pop(int *top,int st[])
{
    if(*top==-1) 
        printf("Stack is empty");
    else 
    {
        printf("Deleted number: %d\n",st[*top]);
        (*top)--; 
    }
}
void main()
{
    int n;
    printf("Enter size of stack: ");
    scanf("%d",&n);
    int st[n],top=-1;
    top=push(top,st,n,1);
    top=push(top,st,n,2);
    top=push(top,st,n,3);
    top=push(top,st,n,4);
    top=push(top,st,n,5);
    printf("Normal Stack: ");
    for (int i = 0; i <=top; i++)
    {
        printf("%d ",st[i]);
    }
    printf("\nUpdated stack:\n");

    pop(&top,st);
    for (int i = 0; i <=top; i++)
    {
        printf("%d ",st[i]);
    }
    printf("\n");

    pop(&top,st);
    for (int i = 0; i <=top; i++)
    {
        printf("%d ",st[i]);
    }
    printf("\n");

    pop(&top,st);
    for (int i = 0; i <=top; i++)
    {
        printf("%d ",st[i]);
    }
    printf("\n");

    pop(&top,st);
    for (int i = 0; i <=top; i++)
    {
        printf("%d ",st[i]);
    }
    printf("\n");

    pop(&top,st);
    for (int i = 0; i <=top; i++)
    {
        printf("%d ",st[i]);
    }   
    
}