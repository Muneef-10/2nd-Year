//WITHOUT STL METHOD-2
#include<iostream>
#define SIZE 5
using namespace std;
void enqueue(int q[],int *f,int*r,int x)
{
    if(*r==SIZE-1) cout<<"Stack is full"<<endl;
    else
    {
        (*r)++;
        if(*f==-1) *f=0;
        q[*r]=x;
    }
}
int dequeue(int q[],int *f,int *r)
{
    int t;
    if(*f==-1) 
    {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    else
    {
        t=q[*f];
        (*f)++;
        if(*f>*r)
        {
            *f=-1;
            *r=-1;
        }
        return t;
    }
}
void push(int q1[],int *f1,int *r1, int x)
{
    enqueue(q1,f1,r1,x);
}
int pop(int q1[],int q2[],int *f1,int*f2,int*r1,int*r2)
{

    if(*f1==-1) 
    {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    else
    {
        while(*f1!=*r1)
        {
            enqueue(q2,f2,r2,dequeue(q1,f1,r1));
        }
        int t=dequeue(q1,f1,r1);
        while(*f2!=-1)
        {
            enqueue(q1,f1,r1,dequeue(q2,f2,r2));
        }
        return t;
    }
    
}
void display(int q1[],int f1,int r1)
{
    if(f1==-1)  cout<<"Stack is empty";
    int i;
    for(i=r1;i>=f1;i--)
    {
        cout<<q1[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int q1[SIZE],q2[SIZE],f1=-1,f2=-1,r1=-1,r2=-1;
    push(q1,&f1,&r1,12);
    push(q1,&f1,&r1,15);
    push(q1,&f1,&r1,18);
    push(q1,&f1,&r1,-21);
    push(q1,&f1,&r1,-24);
    display(q1,f1,r1);

    cout<<"Deleted element: "<<pop(q1,q2,&f1,&f2,&r1,&r2)<<endl;
    display(q1,f1,r1);

    cout<<"Deleted element: "<<pop(q1,q2,&f1,&f2,&r1,&r2)<<endl;
    display(q1,f1,r1);

    cout<<"Deleted element: "<<pop(q1,q2,&f1,&f2,&r1,&r2)<<endl;
    display(q1,f1,r1);
    return 0;
}