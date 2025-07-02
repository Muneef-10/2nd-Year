#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct Node
{
    struct Node *prev;
    struct Node *next;
    int data;
} node;
node* start=NULL;
void create()
{
    int n;
    printf("Enter element: ");
    scanf("%d",&n);
    start=(node*)malloc(sizeof(node));
    start->prev=NULL;
    start->data=n;
    start->next=NULL;
}
void InsertFront()
{
    int n;
    printf("Enter element in front: ");
    scanf("%d",&n);
    node* tmp=(node*)malloc(sizeof(node));
    node *curr=start;
    curr->prev=tmp;
    tmp->data=n;
    tmp->next=curr;
    tmp->prev=NULL;
    start=tmp;
}
void InsertEnd()
{
    int n;
    printf("Enter element in last: ");
    scanf("%d",&n);
    node* tmp=(node*)malloc(sizeof(node));
    node *curr=start;
    while(curr->next!=NULL) curr=curr->next;
    tmp->data=n;
    tmp->next=NULL;
    curr->next=tmp;
    tmp->prev=curr;
}
void display()
{
    node *temp=start;
    if(start==NULL) printf("List not found\n");
    else
    {
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    }
}
void main()
{
    int a;
    do
    {
        printf("Press [1] to create list: \n");
        printf("Press [2] to insert in front: \n");
        printf("Press [3] to inssert in end: \n");
        printf("Press [4] to insert intermediate: \n");
        printf("Press [5] to delete from front: \n");
        printf("Press [6] to delete from last: \n");
        printf("Press [7] to delete intermediate: \n");
        printf("Press [8] to check size: \n");
        printf("Press [9] to check list is empty or not: \n");
        printf("Press [0] to exit: \n");
        scanf("%d",&a);
        switch(a)
        {
            case 0:
                printf("Exit...");
                break;
            case 1:
                create();
                break;
            case 2:
                InsertFront();
                break;
            case 3:
                InsertEnd();
                break;
            case 4:
                display();
                break;
            default:
                printf("Invalid input...");
                break;
        }
    } while (a!=0);
    
}