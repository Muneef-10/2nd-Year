#include<stdio.h>
#include<string.h>
void push(char str[],char st[][20],int *top)
{
    (*top)++;
    strcpy(st[*top],str);
}
char *pop(char st[][20],int *top)
{
    return st[(*top)--];
}
void PostfixToInfix(char s[],char st[][20],int *top)
{
    int l=strlen(s);
    for (int i = 0; i < l; i++)
    {
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')
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
            strcat(ans,b);
            strcat(ans,str);
            strcat(ans,a);
            strcat(ans,")");
            push(ans,st,top);
        }
    }
    
}
void main()
{
    char s[20],st[20][20];
    int top=-1;
    printf("Enter postfix expression:: ");
    scanf("%s",&s);
    PostfixToInfix(s,st,&top);
    printf("%s",st[top]);
}