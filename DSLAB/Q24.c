//Given a sorted linked list WAP to remove duplicates from the list..
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
void dlt()
{
    node *curr=start;
    while(curr!=NULL && curr->next!=NULL)
    {
        while(curr->next != NULL && curr->data==curr->next->data)
        {
            node* tmp=curr->next;
            curr->next=tmp->next;
            if(curr->next!=NULL) curr->next->prev=curr;
            tmp->next=NULL;
            tmp->prev=NULL;
            free(tmp);
        }
        curr=curr->next;
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

    printf("After delete duplicate list: ");
    dlt();
    display();
}