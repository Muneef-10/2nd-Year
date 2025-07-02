// Given a linked list and a number n, design an algorithm and write a program to find the value at the n'th node from end of this linked list(using Doubly linked list).
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}node;
node *create()
{
    int val;
    printf("Enter element: ");
    scanf("%d",&val);
    node *tmp=(node *)malloc(sizeof(node));
    tmp->prev=NULL;
    tmp->data=val;
    tmp->next=NULL;
    return tmp;
}
void insert(node **start,node **last)
{
    node *tmp=create();
    if(*start==NULL)
    {
        *start=tmp;
        *last=tmp;
    }
    else
    {
        (*last)->next=tmp;
        tmp->prev=(*last);
        (*last)=tmp;
    }
}
void display(node *start)
{
    node *tmp=start;
    while (tmp!=NULL)
    {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}
void find(node *start,node *last)
{
    int n;
    printf("Enter node number from last: ");
    scanf("%d",&n);
    node *tmp=last;
    int i=0;
    while(i!=n-1)
    {
        i++;
        tmp=tmp->prev;
    }
    printf("Element at last %d position is: %d\n",n,tmp->data);
}
void main()
{
    node *start=NULL,*last=NULL;
    int choice;
    do
    {
        printf("Press [1] to insert node\n");
        printf("Press [2] to find element from last\n");
        printf("Press [0] exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:
                printf("Exit..");
                break;
            case 1:
                insert(&start,&last);
                display(start);
                break;
            case 2:
                find(start,last);
                break;
            default:
                printf("Invalid input, try again..");
                break;
            
        }
    } while (choice!=0);
    
}