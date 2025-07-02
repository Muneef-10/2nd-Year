#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define SIZE 20
int pres(char ch)
{
    if(ch=='+' || ch=='-') return 1;
    if(ch=='*' || ch=='/') return 2;
    return 0;
}
bool IsEmpty(int *top)
{
    return (*top)==-1;
}
void reverse(char s[],int n)
{
    char tmp;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }
    for (int i = 0; i < n/2; i++)
    {
        tmp=s[i];
        s[i]=s[n-1-i];
        s[n-1-i]=tmp;
    }
}
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
void main()
{
    int top=-1,st[SIZE];
    char s[]="(A-B/C)*(A/K-L)",ans[20]="";
    // char s[]="((h*a+b)-c*(d/e))+f",ans[20]="";
    int n=strlen(s);   
    reverse(s,n);
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='(') push(&top,st,s[i]);
        else if(s[i]==')')
        {
            while(st[top]!='(')
            {
                char t=(char) pop(&top,st);
                strncat(ans,&t,1);
            }
            pop(&top,st);
        }
        else if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z')
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
            push(&top,st,s[i]);
        }
    }
    while(!IsEmpty(&top))
    {
        char t=(char) pop(&top,st);
        strncat(ans,&t,1);
    }
    int l=strlen(ans);
    reverse(ans,l);
    printf("%s",ans);
}