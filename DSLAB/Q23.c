//given a doubly link list WAP to reverse a list without using any extra space
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
}node;
node* start=NULL;
void create()
{
    int n;
    printf("Enter element: ");
    scanf("%d",&n);
    start=(node*)malloc(sizeof(node));
    start->data=n;
    start->prev=NULL;
    start->next=NULL;
}
void InsertLast()
{
    int n;
    printf("Enter element: ");
    scanf("%d",&n);
    node *tmp=(node*)malloc(sizeof(node));
    node *curr=start;
    while(curr->next!=NULL) curr=curr->next;
    curr->next=tmp;
    tmp->prev=curr;
    tmp->data=n;
    tmp->next=NULL;
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
    create();
    InsertLast();
    InsertLast();
    InsertLast();
    InsertLast();
    InsertLast();
    printf("Normal list: ");
    display();

    reverse();
    printf("Reverse list: ");
    display();

}