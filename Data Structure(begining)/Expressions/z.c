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
// int up(int *top,int st[])
// {
//     return st[*top];
// }
void main()
{
    int top=-1,st[20];
    char s[]="AB+CD-*",ans[20]="";
    int n=strlen(s);
    for (int i = 0; i < n; i++)
    {
        if(s[i]>='A' && s[i]<= 'Z') push(&top,st,'xmnd');
    }
        printf("%c",st[top]);
    
    
}