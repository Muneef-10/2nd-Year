#include<iostream>
using namespace std;
void push(char ch, char st[], int *top, int n)
{
    (*top)++;
    st[*top]=ch;
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
    cout<<"s = ";
    cin>>s;
    int n=s.length(),top=-1,flag=0;
    char st[n];
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
            push(s[i],st,&top,n);
        else if((s[i]==')' && !IsEmpty(&top) && st[top]=='(') || (s[i]=='}' && !IsEmpty(&top) && st[top]=='{') || (s[i]==']' && !IsEmpty(&top) && st[top]=='['))
            pop(&top);
        else 
        {
            cout<<"false";
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        if(IsEmpty(&top))
            cout<<"true";
        else 
            cout<<"false";
    }

    return 0;
}