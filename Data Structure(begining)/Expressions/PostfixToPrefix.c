#include<stdio.h>
#include<string.h>
#include<stdbool.h>
void push(char st[][20],char str[],int *top)
{
    (*top)++;
    strcpy(st[*top],str);
}
char *pop(char st[][20],int *top)
{
    return st[(*top)--];
}
void PostfixToPrefix(char st[][20],int *top,char s[])
{
    int l=strlen(s);
    char ans[20]="";

    for (int i = 0; i < l; i++)
    {
        if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z')
        {
            char str[2]={s[i],'\0'};
            push(st,str,top);
        }
        else 
        {
            char *a=pop(st,top);
            char *b=pop(st,top);
            char str[2]={s[i],'\0'};
            strcpy(ans,str);
            strcat(ans,b);
            strcat(ans,a);
            push(st,ans,top);
        }
    }
}
// void display(char st[][20],int top)
// {
//     for (int i = 0; i <=top; i++)
//     {
//         printf("%s ",st[i]);
//     }
    
// }
void main()
{
    char s[20];
    char st[20][20];
    int top=-1;
    printf("Enter postfix expression: ");
    scanf("%s",s);
    
    PostfixToPrefix(st,&top,s);
    printf("%s ",st[top]);
    // display(st,top);
}