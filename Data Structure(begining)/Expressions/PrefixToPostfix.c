#include<stdio.h>
#include<string.h>
void reverse(char s[])
{
    int l=strlen(s);
    for (int i = 0; i < l/2; i++)
    {
        char tmp=s[i];
        s[i]=s[l-1-i];
        s[l-i-1]=tmp;
    }
}
void push(char st[][20],int *top,char str[])
{
    (*top)++;
    strcpy(st[*top],str);
}
char *pop(char st[][20],int *top)
{
    return st[(*top)--];
}
void PrefixToPostfix(char s[],char st[][20],int *top)
{
    int l=strlen(s);
    for (int i = 0; i < l; i++)
    {
        if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z')
        {
            char str[2]={s[i],'\0'};
            push(st,top,str);
        }
        else
        {
            char *a=pop(st,top);
            char *b=pop(st,top);
            char str[2]={s[i],'\0'};
            char ans[40]="";
            strcat(ans,a);
            strcat(ans,b);
            strcat(ans,str);
            push(st,top,ans);
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
    PrefixToPostfix(s,st,&top);
    printf("%s",st[top]);
}