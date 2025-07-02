#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define SIZE 15

int pres(char ch)
{
    if(ch=='+' || ch=='-') return 1;
    if(ch=='*' || ch=='/') return 2;
    return 0;
}
void push(int *top,int x,int st[])
{
    (*top)++;
    st[*top]=x;
}
int pop(int *top,int st[])
{
    int val=st[*top];
    (*top)--;
    return val;
}
bool IsEmpty(int *top)
{
    return (*top)==-1;
}
void main()
{
    int top=-1,st[SIZE];
    char ans[20]="",s[]="((h*a+b)-c*(d/e))+f";
    int n=strlen(s);
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='(')
        push(&top,s[i],st);
        else if(s[i]==')')
        {
            while(st[top]!='(')
            {
                char t=(char) pop(&top,st);
                strncat(ans,&t,1);
            }
            pop(&top,st);
        }
        else if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')
        {
            strncat(ans,&s[i],1);
        }
        else
        {
            while(!IsEmpty(&top) && pres(s[i])<=pres(st[top]) && st[top]!='(')
            {
                char t=(char)pop(&top,st);
                strncat(ans,&t,1);
            }
            push(&top,s[i],st);
        }
    }
    while(!IsEmpty(&top))
    {
        char t=(char) pop(&top,st);
        strncat(ans,&t,1);
    }
    printf("%s",ans);
    
}