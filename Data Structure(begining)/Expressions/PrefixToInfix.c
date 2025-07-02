#include<stdio.h>
#include<string.h>
void reverse(char str[])
{
    int l=strlen(str);
    for (int i = 0; i < l; i++)
    {
        if(str[i]=='(') str[i]=')';
        else if(str[i]==')') str[i]='(';
    }
    for (int i = 0; i < l/2; i++)
    {
        char tmp=str[l-1-i];
        str[l-1-i]=str[i];
        str[i]=tmp;
    }   
}
void push(char s[],char st[][20],int *top)
{
    (*top)++;
    strcpy(st[*top],s);
}
char *pop(char st[][20],int *top)
{
    return st[(*top)--];
}
void PrefixToInfix(char s[],char st[][20],int *top)
{
    int l=strlen(s);
    for (int i = 0; i < l; i++)
    {
        if(s[i]>='a'&&s[i]<='z' || s[i]>='A'&&s[i]<='Z')
        {
            char str[2]={s[i],'\0'};
            push(str,st,top);
        }
        else
        {
            char ans[20]="";
            char *a=pop(st,top);
            char *b=pop(st,top);
            char str[2]={s[i],'\0'};
            strcat(ans,"(");
            strcat(ans,a);
            strcat(ans,str);
            strcat(ans,b);
            strcat(ans,")");
            push(ans,st,top);
        }
    }
    
}
void main()
{
    char s[20],st[20][20];
    int top=-1;
    printf("Enter prefix expression: ");
    scanf("%s",&s);
    reverse(s);
    PrefixToInfix(s,st,&top);
    //reverse(st[top]);
    printf("%s",st[top]);
}