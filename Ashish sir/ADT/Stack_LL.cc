#include<iostream>
using namespace std;
typedef struct Node
{
    int data;
    struct Node* next;
}node;
typedef struct Stack
{
    node* top;
}stack;
void initializestack(stack *st)
{
    (st)->top=NULL;
}
node *createnode(int val)
{
    node* tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    return tmp;
}
void push(stack **st,int val)
{
    node* tmp=createnode(val);
    tmp->next=(*st)->top;
    (*st)->top=tmp;
}
int pop(stack *st)
{
    if((st)->top==NULL)
    {
        cout<<"Stack is empty\n";
        return 0;
    }
    else{
    node*tmp=(st)->top;
    (st)->top=tmp->next;
    int v=tmp->data;
    tmp->next=NULL;
    free(tmp);
    return v;
    }
}
void display(stack *st)
{
    node* tmp=(st)->top;
    while(tmp!=NULL)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}
int main()
{
    stack *st=(stack*)malloc(sizeof(stack));
    initializestack(st);
    push(&st,10);
    push(&st,15);
    push(&st,20);
    push(&st,25);
    display(st);

    cout<<"Deleted value: "<<pop(st)<<endl;
    display(st);
    cout<<"Deleted value: "<<pop(st)<<endl;
    display(st);
    cout<<"Deleted value: "<<pop(st)<<endl;
    display(st);
    cout<<"Deleted value: "<<pop(st)<<endl;

    display(st);
    cout<<"Deleted value: "<<pop(st)<<endl;
    display(st);
    return 0;
}