//WITHOUT STL METHOD-1

#include<iostream>
#define SIZE 5
using namespace std;

void enqueue(int q[],int *f,int*r,int v)
{
    if(*r==SIZE-1)
    {
        cout<<"Stack is full"<<endl;
    }
    if(*f==-1) (*f)++;
    q[++(*r)]=v;
}

int dequeue(int q[],int *f,int *r)
{
    int v=-1;
    if(*f==-1)  cout<<"Stack is empty"<<endl;
    else if(*f==*r) 
    {
        v=q[*f];
        *f=-1;
        *r=-1;
    }
    else 
    {
        v=q[*f];
        (*f)++;
    }
    return v;
}
bool isEmpty(int f)
{
    return f==-1;
}
void push(int q1[],int q2[],int *f1,int *r1,int *f2,int *r2,int v)
{
    if(*r1==SIZE-1)
    {
        cout<<"Stack is full"<<endl;
    }
    enqueue(q2,f2,r2,v);
    while(!isEmpty(*f1))
    {
        enqueue(q2,f2,r2,dequeue(q1,f1,r1));
    }
    for (int i = 0; i <=*r2; i++)
    {
        q1[i]=q2[i];
    }
    int t1=*f1;
    *f1=*f2;
    *f2=t1;

    int t2=*r1;
    *r1=*r2;
    *r2=t2;
}
int pop(int q[],int *f,int*r)
{
    dequeue(q,f,r);
}

void display(int q[],int f,int r)
{
    while(f<=r&&f!=-1)
    {
        cout<<q[f++]<<" ";
    }
    cout<<endl;
}
int main()
{
    int q1[SIZE],q2[SIZE],f1=-1,f2=-1,r1=-1,r2=-1;
    push(q1,q2,&f1,&r1,&f2,&r2,10);
    push(q1,q2,&f1,&r1,&f2,&r2,15);
    push(q1,q2,&f1,&r1,&f2,&r2,20);
    push(q1,q2,&f1,&r1,&f2,&r2,25);
    display(q1,f1,r1);

    cout<<"Deleted elements: "<<pop(q1,&f1,&r1)<<endl;
    display(q1,f1,r1);

    cout<<"Deleted elements: "<<pop(q1,&f1,&r1)<<endl;
    display(q1,f1,r1);

    cout<<"Deleted elements: "<<pop(q1,&f1,&r1)<<endl;
    display(q1,f1,r1);

    cout<<"Deleted elements: "<<pop(q1,&f1,&r1)<<endl;
    display(q1,f1,r1);
    
    cout<<"Deleted elements: "<<pop(q1,&f1,&r1)<<endl;
    display(q1,f1,r1);
    return 0;
}