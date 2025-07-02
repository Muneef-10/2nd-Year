// Given a linked list and a number n, design an algorithm and write a program to find the value at the n'th node from end of this linked list(using singly linked list).
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}node;
node *create()
{
    int val;
    printf("Enter element: ");
    scanf("%d",&val);
    node *tmp=(node *)malloc(sizeof(node));
    tmp->next=NULL;
    tmp->data=val;
    return tmp;
}
void insert(node **start)
{
    node *tmp=create();
    if(*start==NULL) *start=tmp;
    else
    {
        node *curr=(*start);
        while(curr->next!=NULL) curr=curr->next;
        curr->next=tmp;
    }
}
void display(node *start)
{
    node *tmp=start;
    while(tmp!=NULL)
    {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}
int count(node *start)
{
    int c=0;
    node *curr=start;
    while(curr!=NULL)
    {
        c++;
        curr=curr->next;
    }
    return c;
}
void find(node *start,int n)
{
    int size=count(start);
    int x=0;
    node *curr=start;
    while(x!=(size-n))
    {
         curr=curr->next;
         x=x+1;
    }
    printf("Element at last %d position is: %d\n",n,curr->data);
}
void main()
{
    node *start=NULL;
    int choice;
    do
    {
        printf("Press [1] for insert node\n");
        printf("Press [2] to find element from last\n");
        printf("Press [0] for exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:
                printf("Exit..");
                break;
            case 1:
                insert(&start);
                printf("Linked list: ");
                display(start);
                break;
            case 2:
            {
                int n;
                printf("Enter node number from last: ");
                scanf("%d",&n);
                find(start,n);
                break;
            }
            default:
                printf("Invalid input, try again..");
                break;

        }
    } while (choice!=0);
    
}