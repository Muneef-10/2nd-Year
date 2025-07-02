#include<stdio.h>
int push(int *top,int n,int st[],int v)
{
   
    if(*top==n-1)
    {
        printf("Stack is full\n");
        return *top;
    }
    else
    {
        (*top)++;
        st[*top]=v;
        return *top;
    }
}
void main()
{
    int n,a=0;
    printf("Enter size of Stack: ");
    scanf("%d",&n);
    int st[n],top=-1;
        a=push(&top,n,st,1);
        a=push(&top,n,st,2);
        a=push(&top,n,st,3);
        a=push(&top,n,st,4);

    for (int i = 0; i <=a; i++)
    {
        printf("%d ",st[i]);
    }
    
}