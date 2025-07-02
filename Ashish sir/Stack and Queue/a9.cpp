#include<iostream>
#include<string>
#define SIZE 20
using namespace std;
int pres(char c)
{
    switch(c)
    {
        case '+': return 1;
        case '-': return -1;
        case '*': return 2;
        case '/': return -2;
    }
}
char oper(int a)
{
    switch(a)
    {
        case 1: return '+';
        case -1: return '-';
        case 2: return '*';
        case -2: return '/';
    }
}
int isEmpty(int *top)
{
    return *top==-1;
}
void push(int st[],int *top,int x)
{
    (*top)++;
    st[*top]=x;
}
int pop(int st[],int*top)
{
    int v=st[*top];
    (*top)--;
    return v;
}
int main()
{
    int top=-1,st[SIZE];
    string ans = "";
    string s = "((a+b)-c*(d/e))+f";
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='(')
          push(st,&top,s[i]);
        else if(s[i]==')')
        {
            while(st[top]!='(')
            {
                int t=pop(st,&top);
                ans+=char(t);
            }
            pop(st,&top);
        }
        else if(s[i]>='a' && s[i]<='z')
          ans=ans+s[i];
        else 
        {
            while(!isEmpty(&top) && abs(pres(s[i])) <= abs(pres(st[top])) && st[top]!='(')
            {
                int t=pop(st,&top);
                ans+=char(t);
            }
            push(st,&top,s[i]);
        }
    }
    while(!isEmpty(&top))
    {
        int t=pop(st,&top);
        ans+=char(t);
    }
    cout<<"Postfix expression: "<<ans<<endl;
    return 0;
}