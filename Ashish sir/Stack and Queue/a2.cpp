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
void enqueue(int st1[],int st2[],int *top1,int *top2,int x)
{
    if(*top1==SIZE - 1)
        cout<<"\nQueue is full";
    else
    {
        while((*top1)!=-1)
        {
            push(st2,top2,pop(st1,top1));
        }
        push(st1,top1,x);
        while((*top2)!=-1)
        {
            push(st1,top1,pop(st2,top2));
        }
    }
}

void display(int st1[],int top1)
{
    for (int i = top1; i >=0; i--)
    {
        cout<<st1[i]<<" ";
    }
    cout<<endl;
}

int dequeue(int st1[],int *top1)
{
    int x=0;
    if(*top1==-1) cout<<"Queue is empty";
    else{

    x=st1[(*top1)];
    cout<<"\nDeleted number: "<<x<<endl;
    (*top1)--;
    }
    return x;
}

int main()
{
    int s1[SIZE],s2[SIZE],top1=-1,top2=-1;
    enqueue(s1,s2,&top1,&top2,10);
    enqueue(s1,s2,&top1,&top2,15);
    enqueue(s1,s2,&top1,&top2,20);
    display(s1,top1);

    dequeue(s1,&top1);
    display(s1,top1);

    dequeue(s1,&top1);
    display(s1,top1);

    dequeue(s1,&top1);
    display(s1,top1);
    
    dequeue(s1,&top1);
    display(s1,top1);


    return 0;
}