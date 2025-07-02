#include<iostream>
using namespace std;
void push(char ch,char st[],int *top)
{
    (*top)++;
    st[*top]=ch;
}
void pop(int *top)
{
    (*top)--;
}
bool isEmpty(int *top)
{
    if(*top==-1) return true;
    else return false;
}
int main()
{
    int n,flag=0,top=-1;
    string s;
    cin>>s;
    n=s.length();
    char st[n];
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='(')
        {
            push(s[i],st,&top);
        }
        else if(s[i]==')'&&!isEmpty(&top)&&s[top]=='(')
        {
            pop(&top);
        }
        else 
        {
            cout<<"no";
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        if(isEmpty(&top))
        {
            cout<<"Matched";
        }
        else
        {
            cout<<"Not matched";
        }
    }
    

    return 0;
}