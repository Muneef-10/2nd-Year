//Implement stack using linked list.
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}node;
typedef struct Stack
{
    node *top;
}stack;
void initialize(stack *st)
{
    st->top=NULL;
}
node *createnode(int val)
{
    node *tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    return tmp;
}
void push(int val,stack *st)
{
    node *tmp=createnode(val);
    tmp->next=st->top;
    st->top=tmp;
}
int pop(stack* st)
{
    if(st->top==NULL) 
    {
        printf("Stack is empty\n");
        return 0;
    }
    else
    {
        node *tmp=st->top;
        int v=st->top->data;
        st->top=tmp->next;
        tmp->next=NULL;
        free(tmp);
        return v;
    }
}
void display(stack *st)
{
    node* tmp=st->top;
    while(tmp!=NULL)
    {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}
void main()
{
    stack *st=(stack*)malloc(sizeof(stack));
    initialize(st);
    push(10,st);
    push(15,st);
    push(20,st);
    push(25,st);
    push(30,st);
    display(st);
    printf("Deleted element: %d\n",pop(st));
    printf("Deleted element: %d\n",pop(st));
    display(st);
}