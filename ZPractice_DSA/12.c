// Design an algorithm and write a program to concatenate two circularly linked lists.

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
void add(node *start, node *start2)
{
    node *tmp=start;
    node *tmp2=start2;
    while(tmp->next!=start) tmp=tmp->next;
    tmp->next=start2;
    while(tmp2->next!=start2) tmp2=tmp2->next;
    tmp2->next=start;
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
    start2=create(start2,35);
    start2->next=start2;
    insertend(start2,40);
    insertend(start2,45);
    insertend(start2,50);
    insertend(start2,55);
    insertend(start2,60);
    printf("1st List: \n");
    display(start);
    printf("2nd List: \n");
    display(start2);
    add(start,start2);
    printf("Concatenate list: \n");
    display(start);
    
}