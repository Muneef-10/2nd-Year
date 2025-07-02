#include<stdio.h>
int push(int *top,int n,int st[])
{
    int x;    
    if(*top==n-1)
    {
        printf("Stack is full\n");
        return *top;
    }
    else
    {
        printf("Enter number: ");
        scanf("%d",&x);
        (*top)++;
        st[*top]=x;
        return *top;
    }
}
void main()
{
    int n,a=0;
    printf("Enter size of Stack: ");
    scanf("%d",&n);
    int st[n],top=-1;
    char ch;
    do
    {
        a=push(&top,n,st);
        // printf("Do you want to add another number(Y/N): ");
        // scanf(" %c",&ch);
    }while(top!=n-1);//ch=='Y'||ch=='y'

    for (int i = 0; i <=a; i++)
    {
        printf("%d ",st[i]);
    }
    
}