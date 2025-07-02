//postfix to prefix

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define SIZE 30

int top=-1;
char s[SIZE][SIZE];
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

void push(char *st)
{
    if(top<SIZE -1)
    strcpy(st[++top],st);
}
char *pop()
{
    if(top>=0)
    {
    return s[top--];
    }
    return 0;
}

char* up()
{
    if(top>=0)
    {
        return s[top];
    }
    return 0;
}
bool isempty()
{
    return top == -1;
}
int main()
{
    char m[SIZE],ans[SIZE];
    int n,p=0;

    printf("Enter: ");
    scanf("%s", s);

    n=strlen(m);
    char result[SIZE];
    for (int i = 0; i < n; i++)
    {
        
    }
    
}