#include<iostream>
using namespace std;
void push(char a,char st[], int n,int*top)
{
    
    (*top)++;
    st[*top]=a;
}
void pop(int *top)
{
    
    (*top)--;
}
bool isEmpty(int *top)
{
    return *top==-1;
}
int main()
{
    
    string s;
    cout<<"Enter parentheses:"<<endl;
    cin>>s;
    int n=s.length(),flag=0;
    int top=-1;
    char st[n];
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
        {
            push(s[i],st,n,&top);
        }
        else if((s[i]==')'&&!isEmpty(&top)&&st[top]=='(')||(s[i]=='}'&&!isEmpty(&top)&&st[top]=='{')||(s[i]==']'&&!isEmpty(&top)&&st[top]=='['))
        {
            pop(&top);
        }
        else 
        {
            cout<<"Not matched";
            flag=1;
            break;
        }
    }
    if(!flag)
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