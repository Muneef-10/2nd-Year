// Given a sorted doubly linked list, design an algorithm and write a program to eliminate duplicates from this list.

#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next,*prev;
}node;
node *start=NULL;
void insert(int val)
{
    node*tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    tmp->prev=NULL;
    if(start==NULL) start=tmp;
    else
    {
        node*curr=start;
        while(curr->next!=NULL) curr=curr->next;
        curr->next=tmp;
        tmp->prev=curr;
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
    printf("\n");
}
void remove1()
{
    node*curr=start;
    while(curr!=NULL)
    {
        while(curr->next!=NULL && curr->data==curr->next->data)
        {
            node*tmp=curr->next;
            curr->next=tmp->next;
            if(tmp->next!=NULL)
            tmp->next->prev=curr;
            tmp->prev=NULL;
            tmp->next=NULL;
            free(tmp);
        }
        curr=curr->next;
    }
}
void main()
{
    insert(10);
    insert(10);
    insert(12);
    insert(14);
    insert(15);
    insert(15);
    insert(15);
    insert(20);
    insert(25);
    insert(30);
    insert(35);
    insert(40);
    insert(40);
    printf("Normal list: ");
    display();
    remove1();
    printf("After removing duplicate element list: ");
    display();
    
}