//Infix to prefix

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define SIZE 30
int top=-1;
char ab[SIZE];
int pre(char ch)
{
    switch (ch)
    {
        case '+' : return 1;
        case '-' : return 1;
        case '*' : return 2;
        case '/' : return 2;
    }
    return -1;
}
int oper(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
void push(char ch)
{
    if(top<SIZE -1)
    ab[++top]=ch;
}
char pop()
{
    if(top>=0)
    return ab[top--];

}
char up()
{
    if(top>=0)
    return ab[top];
}
bool isempty()
{
    return top==-1;
}
int main()
{
    char st[SIZE];
    char s[] = "(A-B/C)*(A/K-L)";
    int n=strlen(s),temp=0,x=0;
    for (int i = 0; i < n; i++)
    {
        if (s[i]=='(')
        {
            s[i]=')';
        }
        else if (s[i]==')')
        {
            s[i]='(';
        }     
    }
    for (int i = 0; i < n/2; i++)
    {
        temp=s[n-1-i];
        s[n-1-i]=s[i];
        s[i]=temp;
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i]=='(')
        {
            push('(');
        }
        else if (s[i]==')')
        {
            while(!isempty() && up()!='(')
            {
                st[x++]=pop();
            }
            pop();
        }
        else if (s[i]>='A' && s[i]<='Z')    
        {
            st[x++]=s[i];
        }
        else if (oper(s[i]))
        {
            while (!isempty() && pre(up())>=pre(s[i]))
            {
                st[x++]=pop();
            }
            push(s[i]);
        }
        
    }
    while (!isempty())
            {
                st[x++]=pop();
            }
    st[x]='\0';
    for (int i = 0; i < x/2; i++)
    {
        temp=st[x-1-i];
        st[x-1-i]=st[i];
        st[i]=temp;;
    }
    printf("Prefix expression: %s", st);   

    return 0;
}