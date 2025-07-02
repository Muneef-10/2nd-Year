//  Given a doubly linked list, design an algorithm and write a program to reverse this list without using any extra space

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
void reverse()
{
    node *curr=start;
    while(curr!=NULL)
    {
        node* tmp=curr->next;
        curr->next=curr->prev;
        curr->prev=tmp;
        if(curr->prev==NULL)
        {
            start=curr;
            return;
        }
        curr=curr->prev;
    }

}
void main()
{
    insert(10);
    insert(15);
    insert(20);
    insert(25);
    insert(30);
    insert(35);
    insert(40);
    printf("Normal list: ");
    display();
    reverse();
    printf("Reverse list: ");
    display();
}