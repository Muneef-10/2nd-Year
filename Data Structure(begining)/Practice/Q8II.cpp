//Given an expression string consisting of opening and closing brackets"{","}","[","]","(",")" design an algorithm and a program to check whether this expression has balanced paranthesis or not.
#include<iostream>
using namespace std;
class Stack
{
    private:
        int top=-1;
            
    public:
        int st[100];
    int push(char ch)
    {
        top++;
        st[top]=ch;
        return top;
    }
    void pop()
    {
        top--;
    }
    bool IsEmpty()
    {
        return top==-1;
    }
    void display()
    {
        if(IsEmpty()) cout<<"Matched";
        else cout<<"Not Matched";

    }
};
int main()
{
    string s;
    cout<<"Enter paranthesis: ";
    cin>>s;
    int n=s.length(),f=0,a=0;
    Stack s1;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')  a=s1.push(s[i]);
        else if((s[i]==')' && !s1.IsEmpty() && s1.st[a]=='(') || (s[i]=='}' && !s1.IsEmpty() && s1.st[a]=='{') || (s[i]==']' && !s1.IsEmpty()) && s1.st[a]=='[')
        s1.pop();
        
    }
    s1.display();
    

    return 0;
}