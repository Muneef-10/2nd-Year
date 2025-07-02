//Given two string and check they are anagram or not.
#include<stdio.h>
#include<string.h>
void sort(char str[],int l1)
{
    for (int i = 0; i < l1-1; i++)
    {
        for (int j = i+1; j < l1; j++)
        {
            if(str[i] > str[j])
            {
                char ch=str[i];
                str[i]=str[j];
                str[j]=ch;
            }
        }
        
    }
    
}
void main()
{
    char str1[50],str2[50];
    printf("Enter string 1: ");
    scanf("%[^\n]s",&str1);
    getchar();
    printf("Enter string 2: ");
    scanf("%[^\n]s",&str2);
    int l1=strlen(str1),flag=0;
    int l2=strlen(str2);
    if(l1!=l2)
    {
        printf("Strigs are not anagram\n");
    }
    else
    {
        sort(str1,l1);
        sort(str2,l2);
        //strcmp(str1,str2)==0 - Equal
        for (int i = 0; i < l1; i++)
        {
            if(str1[i]!=str2[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==1) printf("Strigs are not anagram\n");
        else printf("Strigs are anagram\n");
    }
    
}