//Given an expression string consisting of opening and closing brackets "(",")" design an algorithm and a program to check whether this expression has balanced paranthesis or not.

#include<iostream>
using namespace std;
void push(char s,char ch[],int n,int *top)
{
    (*top)++;
    ch[*top]=s;
}
void pop(int *top)
{
    (*top)--;
}
bool IsEmpty(int *top)
{
    return *top==-1;
}
int main()
{
    string s;
    cout<<"Enter paranthesis:"<<endl;
    cin>>s;
    int n,top=-1,flag=0;
    n=s.length();
    char ch[n];
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='(')
        {
            push(s[i],ch,n,&top);
        }
        else if(s[i]==')'&&!IsEmpty(&top))//ch[top]=='('
        {
            pop(&top);
        }
        else
        {
            cout<<"Not Matched";
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        if(IsEmpty(&top)) cout<<"Matched";
        else cout<<"Not Matched";
    }

    return 0;
}