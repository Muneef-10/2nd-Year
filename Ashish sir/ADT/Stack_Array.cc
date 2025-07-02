#include<iostream>
using namespace std;
typedef struct stack
{
    int top;
    int capacity;
    int *array;
} stack;
stack *createstack(int cap)
{
    stack *st=(stack*)malloc(sizeof(stack));
    st->capacity=cap;
    st->top=-1;
    st->array=(int*)malloc(sizeof(int)*st->capacity);
    return st;
}
void push(stack *st, int val)
{
    if(st->top >= (st->capacity-1)) cout<<"Stack is full"<<endl;
    else
    {
        st->array[++(st->top)]=val;
    }
}
int pop(stack *st)
{
    if(st->top==-1)  cout<<"Stack if empty\n";
    int v=st->array[(st->top)--];
    return v;
}
void display(stack *st)
{
    if(st->top==-1) cout<<"Stack is empty\n";
    else{
    for (int i = 0; i <=st->top; i++)
    {
        cout<<st->array[i]<<" ";
    }
    cout<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter size of array of stack: ";
    cin>>n;
    stack *st=createstack(n);
    push(st,10);
    push(st,15);
    push(st,20);
    push(st,25);
    push(st,30);
    push(st,35);
    display(st);

    cout<<"Deleted element: "<<pop(st)<<endl;
    display(st);

    cout<<"Deleted element: "<<pop(st)<<endl;
    display(st);
    return 0;
}