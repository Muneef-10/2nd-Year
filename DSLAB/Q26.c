// Design an algorithm and write a program to concatenate two circularly linked lists
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *create(int n)
{
    node* tmp=(node*)malloc(sizeof(node));
    tmp->data=n;
    tmp->next=NULL;
    return tmp;
}
void insertend(int n,node* start)
{
    node* tmp=create(n);
    node* curr=start;
    while(curr->next!=start) curr=curr->next;
    curr->next=tmp;
    tmp->next=start;
}
void display(node *start)
{
    if(start==NULL) return ;
    node *tmp=start;
    do
    {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }while(tmp!=start);
    printf("\n");
}
void main()
{
    node *start1=NULL;
    node *start2=NULL;
    start1=create(10);
    start1->next=start1;
    insertend(15,start1);
    insertend(20,start1);
    insertend(25,start1);
    printf("First list: ");
    display(start1);

    start2=create(40);
    start2->next=start2;
    insertend(45,start2);
    insertend(50,start2);
    insertend(55,start2);
    printf("Second list: ");
    display(start2);

    node *curr1=start1;
    while(curr1->next!=start1) curr1=curr1->next;
    curr1->next=start2;

    node* curr2=start2;
    while(curr2->next!=start2) curr2=curr2->next;
    curr2->next=start1;
    printf("Concatenated list: ");
    display(start1);
}