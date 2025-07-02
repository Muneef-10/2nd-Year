/*Design an algorithm and a program to implement stack using array. The program should implement following stack operation.
a)Create() - create an empty stack
b)Push() - push an element k into the stack
c)Pop() - pop an element from the stack and return it
d)IsEmpty() - check if stack is empty or not
e)Size() - find the size of the stack
f)Print() - prints the content of stack*/

#include<iostream>
using namespace std;
int push(int top,int n,int st[])
{
    if(top==n-1) cout<<"Stack is full"<<endl;
    else
    {
        int x;
        cout<<"Enter element: ";
        cin>>x;
        top++;
        st[top]=x;
    }
    return top;
}
int pop(int st[],int top)
{
    if(top==-1) cout<<"Stack is empty"<<endl;
    else 
    {
        cout<<"Deleted element: "<<st[top]<<endl;
        top--;
    }
    return top;
}
bool IsEmpty(int top)
{
    return top==-1;
}
int size(int top)
{
    return (top+1);
}
void print(int st[],int top)
{
    if (top==-1) cout<<"Stack is empty"<<endl;
    else
    {
        cout<<"Stack: ";
    for (int i = 0; i<=top; i++)
    {
        cout<<st[i]<<" ";
    }
    cout<<endl;
    }
    
}
int main()
{
    int n,s,top=-1;
    int a;
    cout<<"Enter size of an stack: ";
    cin>>n;
    int st[n];
    do
    {
        cout<<endl<<"Press [1] for push"<<endl<<"Press [2] for pop"<<endl<<"Press [3] to check stack is empty or not"<<endl<<"Press [4] to check the size of stack"<<endl<<"Press [5] for print"<<endl<<"Press [0] for exit"<<endl;

        cin>>a;
        switch(a)
        {
            case 0:
                cout<<"Exit..";
                break;
            case 1:
                top=push(top,n,st);
                break;
            case 2:
                top=pop(st,top);
                break;
            case 3:
                if(IsEmpty(top)) cout<<"Stack is empty"<<endl;
                else cout<<"Stack is not empty"<<endl;
                break;
            case 4:
                s=size(top);
                cout<<"Size of stack: "<<s<<endl;
                break;
            case 5:
                print(st,top);
                break;
            default:
            cout<<"Invalid input,try again";
        }
    }while(a!=0);
    return 0;
}