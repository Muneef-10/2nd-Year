#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.emplace(6);

    queue<int> t=q;
    while(!t.empty())
    {
        cout<<t.front()<<" ";
        t.pop();
    }
    cout<<endl;

    cout<<"Queue front: "<<q.front()<<endl;
    cout<<"Queue back: "<<q.back()<<endl;
    cout<<"Size: "<<q.size()<<endl;

    q.pop();
    cout<<"Queue front: "<<q.front()<<endl;
    cout<<"Queue back: "<<q.back()<<endl;
    cout<<"Size: "<<q.size()<<endl;
    
    queue<int> temp=q;
    while(!temp.empty())
    {
        cout<<temp.front()<<" ";
        temp.pop();
    }
    cout<<endl;
    q.pop();
    q.pop();
    queue<int> tmp=q;
    while(!tmp.empty())
    {
        cout<<tmp.front()<<" ";
        tmp.pop();
    }
     
    return 0;
}