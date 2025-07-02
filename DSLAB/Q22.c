#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} node;
node *start=NULL;
void create()
{
    int n;
    printf("Enter first element: ");
    scanf("%d",&n);
    start=(node*)malloc(sizeof(node));
    start->data=n;
    start->prev=NULL;
    start->next=NULL;
}
void InsertLast()
{
    int n;
    printf("Enter element in front: ");
    scanf("%d",&n);
    node *tmp=(node*)malloc(sizeof(node));
    node *curr=start;
    while(curr->next!=NULL) curr=curr->next;
    curr->next=tmp;
    tmp->prev=curr;
    tmp->data=n;
    tmp->next=NULL;
}
void InsertFront()
{
    int n;
    printf("Enter element in last: ");
    scanf("%d",&n);
    node *tmp=(node*)malloc(sizeof(node));
    node *curr=start;
    curr->prev=tmp;
    tmp->next=curr;
    tmp->data=n;
    tmp->prev=NULL;
    start=tmp;
}
void InsertMid()
{
    int n,k;
    printf("Enter position: ");
    scanf("%d",&k);
    if(k==1) InsertFront();
    else{
    printf("Enter element: ");
    scanf("%d",&n);
    node *curr=start;
    for (int i = 0; i < k-2; i++)
    {
        curr=curr->next;
    }
    node* tmp=(node*)malloc(sizeof(node));
    tmp->next=curr->next;
    curr->next=tmp;
    tmp->data=n;
    tmp->prev=curr;
    tmp->next->prev=tmp;   
    }     
}
void DltFront()
{
    if(start==NULL) printf("List not found\n");
    else{
        node *curr=start;
    printf("Deleted elemnt: %d\n",curr->data);
    start=start->next;
    curr->next=NULL;
    free(curr);
    }
}
void DltLast()
{
    if(start==NULL) printf("List not found\n");
    else{
    node*curr=start;
    while(curr->next!=NULL) curr=curr->next;
    printf("Deleted element: %d\n",curr->data);
    curr->prev->next=NULL;
    curr->prev=NULL;
    free(curr);
    }
}
void DltMid()
{
    if(start==NULL) printf("List not found\n");
    else{
        int k;
        printf("Enter element position: ");
        scanf("%d",&k);
        if(k==1) DltFront();
        else{
            node *curr=start;
        for (int i = 0; i < k-2; i++)
        {
            curr=curr->next;
        }
        node*tmp=curr->next;
        printf("Deleted element: %d\n",tmp->data);
        curr->next=curr->next->next;
        curr->next->prev=curr;
        tmp->next=NULL;        
        tmp->prev=NULL;
        free(tmp);
        }
    }
}
bool Isempty()
{
    return start==NULL;
}
int size()
{
    int c=0;
    node *tmp=start;
    while(tmp!=NULL) 
    {
        tmp=tmp->next;
        c++;
    }
    return c;
}
void middle()
{
    if(size()%2==0) printf("Size of list is even\n");
    else
    {
        node*curr=start;
        for (int i = 0; i < (size()/2); i++)
        {
            curr=curr->next;
        }
        printf("Middle element: %d\n",curr->data);
    }
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
void main()
{
    int a;
    do
    {
        printf("Press [1] to create list\n");
        printf("Press [2] to insert in front\n");
        printf("Press [3] to insert in last\n");
        printf("Press [4] to insert in 'K' position\n");
        printf("Press [5] to delete in front\n");
        printf("Press [6] to delete in last\n");
        printf("Press [7] to delete in 'K' position\n");
        printf("Press [8] to check empty or not\n");
        printf("Press [9] to check size\n");
        printf("Press [10] to find middle element\n");
        printf("Press [0] to exit\n");
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
                display();
                break;
            case 3:
                InsertLast();
                display();
                break;
            case 4:
                InsertMid();
                display();
                break;
            case 5:
                DltFront();
                display();
                break;
            case 6:
                DltLast();
                display();
                break;
            case 7:
                DltMid();
                display();
                break;
            case 8:
                if(Isempty()) printf("List is empty\n");
                else printf("List is not empty\n");
                break;
            case 9:
                printf("Size is: %d\n",size());
                break;
            case 10:
                middle();
                break;
            default:
                printf("Invalid input, try again...\n");
                break;
        }

    } while (a!=0);
    
}