//Write a program that will reverse a linked list only by traversing it once and without using extra space.
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
void reverse(node **start)
{
    node *curr=(*start);
    node *nxt=NULL;
    node *prev=NULL;
    while(curr!=NULL)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    (*start)=prev;
}
void main()
{
    node *start=NULL;
    int choice;
    do
    {
        printf("Press [1] to insert node\n");
        printf("Press [2] to display\n");
        printf("Press [0] to exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:
                printf("Exit..");
                break;
            case 1:
                insert(&start);
                break;
            case 2:
                printf("Normal linked list: ");
                display(start);
                reverse(&start);
                printf("Reverse linked list: ");
                display(start);
                break;
            default:
                printf("Invalid input, try again..");
                break;

        }
    } while(choice!=0);
    

}