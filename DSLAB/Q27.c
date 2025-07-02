// Write an algorithm and a program that will split a circularly linked list into two circularly linkedlist provided position from where circular linked list has to be splitted.(Single Circular Link list)
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
void display(node* start)
{
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
    node *start=NULL;
    int k;
    start=create(10);
    start->next=start;
    insertend(15,start);
    insertend(20,start);
    insertend(25,start);
    insertend(30,start);
    insertend(35,start);
    insertend(40,start);
    printf("Original linked list: ");
    display(start);
    printf("Enter position where you want to split: ");
    scanf("%d",&k);
    node* curr=start;
    for (int i = 0; i < k-1; i++)
    {
        curr=curr->next;
    }
    node* start1=curr->next;
    curr->next=start;
    printf("First list: ");
    display(start);
    node* curr1=start1;
    while(curr1->next!=start) curr1=curr1->next;
    curr1->next=start1;
    printf("Second list: ");
    display(start1);
}