#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*next;
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
    if((*start)==NULL) (*start)=tmp;
    else{
    node *curr=(*start);
    while(curr->next!=NULL) curr=curr->next;
    curr->next=tmp;
    }
}
node *reverse(node *start)
{
    if(start==NULL || start->next==NULL) return start;
    node *tmp=reverse(start->next);
    start->next->next=start;
    start->next=NULL;
    return tmp;
}
void display(node *start)
{
    if(start==NULL){
        printf("list not found");
    }
    else{
        node *temp=start;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        
    }
    printf("\n");
}
void main()
{
    node *start=NULL;
    int choice;
    do
    {
        printf("Press [1] for insert an element\n");
        printf("Press [2] for display\n");
        printf("Press [0] for exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:
                printf("Exit..\n");
                break;
            case 1:
                insert(&start);
                break;
            case 2:
                printf("Normal linked list: ");
                display(start);
                start=reverse(start);
                printf("Reverse linked list: ");
                display(start);
                break;
            default:
                printf("Invalid input, try again..\n");
                break;
        }
        
    } while (choice!=0);
    
    
}