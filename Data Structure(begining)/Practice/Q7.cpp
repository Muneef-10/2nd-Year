/*Given an expression string consisting of opening and closing brackets"{","}","[","]","(",")" design an algorithm and a program to check 
whether this expression has balanced paranthesis or not.*/

#include<iostream>
#include<string>
using namespace std;
void push(int ch,char st[],int *top,int n)
{
    (*top)++;
    st[*top]=ch;
}
void pop(int *top)
{
    (*top)--;
}
bool Isempty(int *top)
{
    return *top==-1;
}
int main()
{
    int x;
    cout<<"Enter limit: ";
    cin>>x;
    string s;
    for(int a=0;a<x;a++)
    {
        
        cout<<"Enter paranthesis:  ";
        cin>>s;  
        int top=-1,n;
        n=s.length();
        char st[n];
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[') 
            {
                push(s[i],st,&top,n);
            }
            else if ((s[i]==')'&&!Isempty(&top)&&st[top]=='(') || (s[i]=='}'&&!Isempty(&top)&&st[top]=='{') || (s[i]==']'&&!Isempty(&top)&&st[top]=='['))
            {
                pop(&top);
            }            
        }
        if(Isempty(&top)) 
        {
            cout<<"Balanced"<<endl;
        }
        else
        {
            cout<<"Unbalanced"<<endl;
        }
        
    }

    return 0;
}