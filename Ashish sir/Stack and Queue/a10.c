// postfix evaluaion
#include<stdio.h>
#include<string.h>
#define SIZE 20
void push(int st[],int *top,int x)
{
    (*top)++;
    st[*top]=x;
}

int pop(int st[],int *top)
{
    int v=st[*top];
    (*top)--;
    return v;
}
int up(int top,int st[])
{
    return st[top];
}
int eval(int a,int b,char ch)
{
    switch (ch)
    {
        case '+' : return a+b;
        case '-' : return a-b;
        case '*' : return a*b;
        case '/' : return a/b;
    }
}
int main()
{
    char s[]="12+33/4*3*-5-";
    // char s[]="231*+9-";
    int top=-1,st[SIZE];
    int i=0,n=strlen(s);
    while(i<n)
    {
        if(s[i] >= '0'&&s[i] <= '9')
           push(st, &top, s[i]-'0');
        else 
        {
            int b=up(top,st);
            pop(st,&top);
            int a=up(top,st);
            pop(st,&top);
            int res=eval(a,b,s[i]);
            push(st,&top,res);
        }
        i++;
    }
    printf("Result is: %d", up(top,st));
    return 0;
}