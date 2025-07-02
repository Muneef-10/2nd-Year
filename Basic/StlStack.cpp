#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.emplace(60);
    cout<<"Element at top: "<<st.top()<<endl;

    st.pop();
    cout<<"Element at top: "<<st.top()<<endl;
    cout<<"Stack size: "<<st.size()<<endl;
    cout<<(st.empty()? "Stack is empty" : "Stack is not empty")<<endl;  //? for true : for false
    //for printing:- 

    stack<int> temp=st;
    while(!temp.empty())
    {
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;
    st.pop();
    st.pop();

    stack<int> tmp=st;
    while(!tmp.empty())
    {
        cout<<tmp.top()<<" ";
        tmp.pop();
    }
    
    return 0;
}