// Write an algorithm and a program that will split a circularly linked list into two circularly linkedlist provided position from where circular linked list has to be splitted.(Single Circular Link list)
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;

node *create(node*start,int val)
{
    node *tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    return tmp;
}
void insertend(node*start,int val)
{
    node *tmp=create(start,val);
    node*curr=start;
    while(curr->next!=start) curr=curr->next;
    curr->next=tmp;
    tmp->next=start;
}
void display(node*start)
{
    node* tmp=start;
    do 
    {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }while(tmp!=start);
    printf("\n");
}
void split(node **start,node**start2)
{
    int n;
    printf("Ente position: ");
    scanf("%d",&n);
    node* curr=*start;
    for (int i = 0; i < n-1; i++)
    {
        curr=curr->next;
    }
    *start2=curr->next;
    curr->next=*start;
    node*tmp=*start2;
    while(tmp->next!=*start) tmp=tmp->next;
    tmp->next=*start2;
    
}
void main()
{
    node *start=NULL;
    node *start2=NULL;
    start=create(start,10);
    start->next=start;
    insertend(start,15);
    insertend(start,20);
    insertend(start,25);
    insertend(start,30);
    insertend(start,35);
    insertend(start,40);
    insertend(start,45);
    insertend(start,50);
    insertend(start,55);
    insertend(start,60);
    display(start);
    split(&start,&start2);
    printf("1st List: \n");
    display(start);
    printf("2nd List: \n");
    display(start2);
}