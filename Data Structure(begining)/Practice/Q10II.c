// Given an empty stack, design an algorithm and a program to reverse a string using this stack (with and without recursion).

#include<stdio.h>
#include<string.h>
void push(int *top,char ch,char st[])
{
    (*top)++;
    st[*top]=ch;
}
char pop(int *top,char st[])
{
    char ch=st[*top];
    (*top)--;
    return ch;
}

void main()
{
    char ch[50]="Data Structure";
    int top=-1,l=0;
    printf("Enter string: ");
    scanf("%[^\n]s",&ch);
    l=strlen(ch);
    char st[l];
    for (int i = 0; i < l; i++)
    {
        push(&top,ch[i],st);
    }
    
    for (int i = 0; i< l; i++)
    {
        printf("%c",pop(&top,st));
    }
    
}