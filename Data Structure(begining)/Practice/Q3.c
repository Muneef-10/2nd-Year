//peek/top :- It checks which is topmost element

#include<stdio.h>
int push(int top,int n,int st[],int v)
{
    if(top==n-1)
    {
        printf("Stack is Full  ");
        return top;
    }
    else
    {
        top++;
        st[top]=v;
        return top;
    }
}
void peek(int top,int n,int st[])
{
    if(top==-1) printf("Stack is Empty  ");
    else printf("\nTopmost element is: %d\n",st[top]);
}
void main()
{
    int n;
    printf("Enter size of stack: ");
    scanf("%d",&n);
    int st[n],top=-1;
        top=push(top,n,st,1);
        top=push(top,n,st,2);
        top=push(top,n,st,3);
        top=push(top,n,st,4);
        top=push(top,n,st,5);
        
        for (int i = 0; i <=top; i++)
        {
            printf("%d ",st[i]);
        }

        peek(top,n,st);
        
}
