//USING STL METHOD-2
#include<iostream>
#include<queue>
using namespace std;
void push(queue<int> &q1,int v)
{
    q1.push(v);
}
int pop(queue<int> &q1,queue<int> &q2)
{
    if(q1.empty())
    {
        cout<<"Stack is empty"<<endl;
        return 0;
    }
    else
    {
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int val=q1.front();
        q1.pop();
        swap(q1,q2);
        return val;
    }
}
void display(queue<int> q1)
{
    while(!q1.empty())
    {
        cout<<q1.front()<<" ";
        q1.pop();
    }
    cout<<endl;
}
int main()
{
    queue<int> q1,q2;
    push(q1,10);
    push(q1,15);
    push(q1,20);
    push(q1,25);
    display(q1);

    cout<<"Deleted element: "<<pop(q1,q2)<<endl;
    display(q1);

    cout<<"Deleted element: "<<pop(q1,q2)<<endl;
    display(q1);

    cout<<"Deleted element: "<<pop(q1,q2)<<endl;
    display(q1);

    cout<<"Deleted element: "<<pop(q1,q2)<<endl;
    display(q1);

    cout<<"Deleted element: "<<pop(q1,q2)<<endl;
    display(q1);
    return 0;
}