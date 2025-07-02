/*Given a string of opening and closing paranthesis, design an algorithm and a program to find the length of the longest valid parenthesis substring. Valid parenthesis substring is a string which contains balanced parenthesis.*/

#include<iostream>
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
    int n,top=-1,flag=0;
    string s;
    int a=0,x;
    cout<<"Enter limit: ";
    cin>>x;
    int arr[x];
    while(a!=x)
    {
    cout<<"Enter paranthesis:  ";
    cin>>s;
    int count=0;
    n=s.length();
    char st[n];
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[') push(s[i],st,&top,n);
        else if ((s[i]==')'&&!Isempty(&top)&&st[top]=='(') || (s[i]=='}'&&!Isempty(&top)&&st[top]=='{') || (s[i]==']'&&!Isempty(&top)&&st[top]=='['))
        {
            pop(&top);
            count++;
        }
        arr[a]=count;
        
    }
    a++;
    }
    for (int i = 0; i < x; i++)
    {
        cout<<arr[i]*2<<endl;
    }
    
    

    return 0;
}