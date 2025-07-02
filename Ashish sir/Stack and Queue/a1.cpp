#include<iostream>
using namespace std;
void enqueue(int q[],int *f,int *r,int v,int n)
{
    if((*r)==n-1)
    {
        cout << "Queue is full"<<endl;
    }
    else
    {
        (*r)++;
        if((*f)==-1)
        {
            (*f)=0;
        }
        q[*r]=v;
    }
}
int dequeue(int q[],int *f,int *r)
{
    int k;
    if(*r==-1)
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    else
    {
        k=q[*f];
        (*f)++;
        if(*f>*r)
        {
            *f=*r=-1;
        }
        return k;
    }

}
void display(int q[],int f, int r)
{
    for (int i = f; i <=r; i++)
    {
        if(i!=-1)
        cout<<q[i]<<" ";
        else 
        cout<<"Queue is empty"<<endl;
    }
    
}

int main()
{
    int n;
    cout<<"Enter the size of queue: ";
    cin>>n;
    int q[n];
    int f=-1,r=-1;
    enqueue(q,&f,&r,12,n);
    enqueue(q,&f,&r,13,n);
    enqueue(q,&f,&r,14,n);
    enqueue(q,&f,&r,15,n);
    enqueue(q,&f,&r,16,n);
    display(q,f,r);
    cout<<endl;
    cout<<"Deleted is: "<<dequeue(q,&f,&r)<<endl;

    display(q,f,r);
    cout<<endl;
    cout<<"Deleted is: "<<dequeue(q,&f,&r)<<endl;

    display(q,f,r);
    cout<<endl;
    cout<<"Deleted is: "<<dequeue(q,&f,&r)<<endl;

    display(q,f,r);
    cout<<endl;
    cout<<"Deleted is: "<<dequeue(q,&f,&r)<<endl;

    display(q,f,r);
    cout<<endl;
    cout<<"Deleted is: "<<dequeue(q,&f,&r)<<endl;

    return 0;
}