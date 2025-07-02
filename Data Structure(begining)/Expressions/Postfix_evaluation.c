#include<stdio.h>
#include<string.h>
void push(int *top,int st[],int val)
{
    (*top)++;
    st[*top]=val;
}
int pop(int *top,int st[])
{
    int x=st[*top];
    (*top)--;
    return x;
}
// int up(int top,int st[])
// {
//     return st[top];
// }
int evaluation(int a, int b, int ch)
{
    switch(ch)
    {
        case '+': return b+a;
        case '-': return b-a;
        case '*': return b*a;
        case '/': return b/a;
    }
}
void main()
{
    int top=-1,st[20];
    char s[]="53+62/*35*+";
    int n=strlen(s);
    for (int i = 0; i < n; i++)
    {
        if(s[i]>='0' && s[i]<= '9') push(&top,st,s[i]-'0');
        else
        {
            int a=pop(&top,st);
            
            int b=pop(&top,st);
            // pop(&top,st);
            int result=evaluation(a,b,s[i]);
            push(&top,st,result);
        }
    }
    printf("Solution of that expression is: %d",st[top]);
    
}