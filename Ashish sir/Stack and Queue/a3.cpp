#include<iostream>
#define SIZE 5
using namespace std;
void push(int st[],int *top,int x)
{
    if(*top==SIZE-1)
        cout<<"Stack is full";
    else
    {
        (*top)++;
        st[*top]=x;
    }
}
int pop(int st[],int *top)
{
    int x;
    if(*top==-1)
        cout<<"Stack is empty";
    else
    {
        x=st[*top];
        (*top)--;
    }
    return x;
}
void enq2(int st1[],int *top1,int x)
{
    if(*top1==SIZE - 1)  cout<<"Queue is full";
    else
    {
        push(st1,top1,x);
    }
}
int deq2(int st1[],int st2[],int *top1,int *top2)
{
    int x=-1;
    if(*top1==-1 && *top2 == -1)  cout<<"Queue is empty"<<endl;
    else
    {
        if(*top2!=-1)
        {
            x=pop(st2,top2);
        }
        else
        {
            while((*top1)!=-1)
        {
            push(st2,top2,pop(st1,top1));
        }
        x=pop(st2,top2);
        }
        return x;
    }
}
void dis2(int st1[],int st2[],int *top1,int *top2)
{
    while((*top1)!=-1)
        {
            push(st2,top2,pop(st1,top1));
        }
    for (int i=*top2; i >=0; i--)
    {
        cout<<st2[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int s1[SIZE],s2[SIZE],top1=-1,top2=-1;

    enq2(s1,&top1,10);
    enq2(s1,&top1,15);
    enq2(s1,&top1,19);
    dis2(s1,s2,&top1,&top2);
    cout<<"Deleted value: "<<deq2(s1,s2,&top1,&top2)<<endl;
    dis2(s1,s2,&top1,&top2);
    cout<<"Deleted value: "<<deq2(s1,s2,&top1,&top2)<<endl;
    dis2(s1,s2,&top1,&top2);
    cout<<"Deleted value: "<<deq2(s1,s2,&top1,&top2)<<endl;
    dis2(s1,s2,&top1,&top2);
    



    return 0;
}