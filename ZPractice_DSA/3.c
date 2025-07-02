// Insert a node in a linked list in a sorted manner.
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}node;
node *start=NULL;
void insert(int val)
{
    node* tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    if(start==NULL) start=tmp;
    else if(start->next==NULL)
    {
        if(tmp->data > start->data)  start->next=tmp;
        else
        {
            tmp->next=start;
            start=tmp;
        }
    }
    else
    {
        node* curr=start;
        if(tmp->data > curr->data)
        {
            while(curr->next!=NULL && tmp->data > curr->next->data)   curr=curr->next;
            tmp->next=curr->next;
            curr->next=tmp;
        }
        else
        {
            tmp->next=start;
            start=tmp;
        }
    }

}
void display()
{
    node* tmp=start;
    while(tmp!=NULL)
    {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
}
void main()
{
    insert(10);
    insert(15);
    insert(20);
    insert(6);
    insert(17);
    insert(12);
    insert(18);
    insert(16);
    insert(24);
    insert(28);
    display();
}