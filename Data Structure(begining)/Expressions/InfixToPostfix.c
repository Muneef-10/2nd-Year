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
int pres(char ch)
{
    if(ch=='+' || ch=='-') return 1;
    if(ch=='*' || ch=='/') return 2;
}
bool isempty(int top)
{
    return top==-1;
}
void main()
{
    char s[50];
    printf("Enter expression: ");
    scanf("%s",&s);
    int l=strlen(s);
    char ans[l],st[l];
    int top=-1,top2=-1;
    for (int i = 0; i < l; i++)
    {
        if(s[i]=='(') push(s[i],st,&top);
        else if(s[i]>='0' && s[i]<='9') push(s[i],ans,&top2);
        else if(s[i]==')')
        {
            while(st[top]!='(')
            {
                push(pop(st,&top),ans,&top2);
            }
            pop(st,&top);
        }
        else 
        {
            while(!isempty(top) && pres(s[i]) <= pres(st[top]) && st[top]!='(') push(pop(st,&top),ans,&top2);
            push(s[i],st,&top);
        }
    }
    while(!isempty(top))
    push(pop(st,&top),ans,&top2);
    for (int i = 0; i <=top2; i++)
    {
        printf("%c",ans[i]);
    }   
}