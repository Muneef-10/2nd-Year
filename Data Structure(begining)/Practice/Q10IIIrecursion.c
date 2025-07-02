// Given an empty stack, design an algorithm and a program to reverse a string using this stack (with and without recursion).

#include<stdio.h>
#include<string.h>
void push(int *top,char ch,char st[])
{
    (*top)++;
    st[*top]=ch;
}
void reverse(int top,char st[])
{
    if(top==-1) return ;
    printf("%c",st[top]);
    reverse(top-1, st);
}
void main()
{
    char ch[50];
    printf("Enter string: ");
    scanf("%[^\n]",&ch);
    int l=strlen(ch),top=-1;
    char st[l];
    for (int i = 0; i < l; i++)
    {
        push(&top,ch[i],st);
    }
    reverse(top,st);
    printf("%c",ch[2]);

}