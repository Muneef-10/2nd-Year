#include<stdio.h>
#include<string.h>
int top=-1;
void push(char st[][20],char ans[])
{
    top++;
    // st[top]=ans;
    strcpy(st[top],ans);
}
void display(char st[][20])
{
    for (int i = 0; i <=top; i++)
    {
        printf("%s ",st[i]);
    }
    
}
void main()
{
    char ans[]="ABCDE";
    char ans2[]="FGHIJ";
    char ans3[]="KLMNO";
    char st[20][20];
    push(st,ans);
    push(st,ans2);
    push(st,ans3);
    display(st);
    printf("\n%s",st[2]);
}