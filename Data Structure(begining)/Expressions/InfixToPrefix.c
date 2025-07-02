#include<stdio.h>
#include<stdbool.h>
#include<string.h>
void push(char ch,char st[],int *top)
{
    (*top)++;
    st[*top]=ch;
}
char pop(char st[],int *top)
{
    char ch=st[*top];
    (*top)--;
    return ch;
}
bool IsEmpty(int top)
{
    return top==-1;
}
int pres(char ch)
{
    if(ch=='+'|| ch=='-') return 1;
    else if(ch=='*'|| ch=='/') return 2;
}
void reverse(char s[],int l)
{
    for (int i = 0; i < l; i++)
    {
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }
    for (int i = 0; i < l/2; i++)
    {
        char ch=s[i];
        s[i]=s[l-1-i];
        s[l-1-i]=ch;
    }    
}
void main()
{
    char s[20];
    printf("Enter expression: ");
    scanf("%s",&s);
    int l=strlen(s);
    char st[l],ans[l];
    int top=-1,top2=-1;
    reverse(s,l);
    for (int i = 0; i < l; i++)
    {
        if(s[i]=='(') push(s[i],st,&top);
        else if(s[i]==')')
        {
            while(st[top]!='(')
            {
                push(pop(st,&top),ans,&top2);
            }
            pop(st,&top);
        }
        else if(s[i]>='0' && s[i]<='9' || s[i]>='a' && s[i]<='z') push(s[i],ans,&top2);
        else
        {
            while(!IsEmpty(top) && pres(s[i])<=pres(st[top]) && st[top]!='(') push(pop(st,&top),ans,&top2);
            push(s[i],st,&top); 
        }
    }
    while(!IsEmpty(top)) push(pop(st,&top),ans,&top2);
    int x=strlen(ans);
    reverse(ans,x);
    for (int i = 0; i <=top2; i++)
    {
        printf("%c",ans[i]);
    }    
}