//USING STL METHOD-1

#include<iostream>
#include<stack>
#include<queue>
using namespace std;
queue<int> q1,q2;
void push(int v)
{
    q2.push(v);
    while(!q1.empty())
    {
        int t=q1.front();
        q1.pop();
        q2.push(t);
    }

    swap(q1,q2);
}
int pop()
{
    if(q1.empty())
    {
        cout<<"Stack is empty"<<endl;
        return 0;
    }
    else
    {    
    int t=q1.front();
    q1.pop();
    return t;
    }
}
void display()
{
    queue <int> temp=q1;
    while(!temp.empty())
    {
        cout<<temp.front()<<" ";
        temp.pop();
    }
    cout<<endl;
}
int main()
{
    stack<int> st;
    push(10);
    push(12);
    push(15);
    push(20);
    display();

    cout<<"Deleted element: "<<pop()<<endl;
    display();

    cout<<"Deleted element: "<<pop()<<endl;
    display();
    
    cout<<"Deleted element: "<<pop()<<endl;
    display();
    
    cout<<"Deleted element: "<<pop()<<endl;
    display();

    cout<<"Deleted element: "<<pop()<<endl;
    display();
    return 0;
}