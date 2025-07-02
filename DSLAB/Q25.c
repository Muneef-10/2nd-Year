/* Write a program to implement circular linked list. The program should implement following operations:
a) Create(k) - creates a circular linked list node with value k.
b)InsertFront() - insert node at the front of list.
c) InsertEnd() - insert node at the end of list.
d)InsertIntermediate() - insert node at any specified position of list.
e) DeleteFront() - delete node from the front of list.
f) DeleteEnd() - delete node from the end of list.
g)DeleteIntermediate() - delete node from any specified position of list.
h)Size() - return size of circular linked list.
i) IsEmpty() - checks whether list is empty or not.*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
    int data;
    struct Node *next;
} node;
node *start=NULL;
node *create()
{
    int n;
    printf("Enter element: ");
    scanf("%d",&n);
    node* tmp=(node*)malloc(sizeof(node));
    tmp->data=n;
    tmp->next=NULL;
    return tmp;
}
void insertfront()
{
    node* tmp=create();
    tmp->next=start;
    start=tmp;
    node* curr=start->next;
    while(curr->next!=start->next) curr=curr->next;
    curr->next=tmp;
}
void insertend()
{
    node* tmp=create();
    node* curr=start;
    while(curr->next!=start) curr=curr->next;
    curr->next=tmp;
    tmp->next=start;
}
void insertanywhere()
{
    int k;
    printf("Enter position: ");
    scanf("%d",&k);
    if(k==1) insertfront();
    else {
        node* tmp=create();
        node* curr=start;
        for (int i = 0; i < k-2; i++)
        {
           curr=curr->next;
        }
        tmp->next=curr->next;
        curr->next=tmp;
    }    
}
void dltfront()
{
    if(start==NULL) 
    {
        printf("List not found\n");
    }
    else {
    node* tmp=start;
    start=start->next;
    node* curr=start;
    while(curr->next!=tmp) curr=curr->next;
    curr->next=start;
    tmp->next=NULL;
    printf("Deleted element: %d\n",tmp->data);
    free(tmp);
    }
}
void dltend()
{
    if(start==NULL) printf("List not found\n");
    else {
    node* curr=start;
    node* prev=NULL;
    while(curr->next!=start)
    {
        prev=curr;
        curr=curr->next;
    } 
    curr->next=NULL;
    prev->next=start;
    printf("Deleted element: %d\n",curr->data);
    free(curr);
    }
}
void dltanywhere()
{
    if(start==NULL) printf("List not found\n");
    else{
    int k;
    printf("Enter positon: ");
    scanf("%d",&k);
    node *curr=start;
    for (int i = 0; i < k-2; i++)
    {
        curr=curr->next;
    }
    node* tmp=curr->next;
    curr->next=tmp->next;
    tmp->next=NULL;
    printf("Deleted element: %d\n",tmp->data);
    free(tmp);    
    }
}
int size()
{
    node* curr=start;
    int c=1;
    while(curr->next!=start)
    {
        curr=curr->next;
        c++;
    }
    return c;
}
bool IsEmpty()
{
    return start==NULL;
}
void display()
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
    int a;
    do
    {
        printf("press [1] to create a link list\n");
        printf("press [2] to insert in front in a link list\n");
        printf("press [3] to insert at end in a link list\n");
        printf("press [4] to insert at position 'P' in  a link list\n");
        printf("press [5] to dlt at front\n");
        printf("press [6] to dlt at end\n");
        printf("press [7] to dlt at position 'p' in a link list\n");
        printf("press [8] to check the size of link list\n");
        printf("press [9] to check list is empty or not\n");
        printf("press [0] to exit\n");
        scanf("%d",&a);
        switch(a)
        {
            case 0:
                printf("Exit..");
                break;
            case 1:
                start=create();
                start->next=start;
                break;
            case 2:
                insertfront();
                display();
                break;
            case 3:
                insertend();
                display();
                break;
            case 4:
                insertanywhere();
                display();
                break;
            case 5:
                dltfront();
                display();
                break;
            case 6:
                dltend();
                display();
                break;
            case 7:
                dltanywhere();
                display();
                break;
            case 8:
                printf("Size of list is: %d\n",size());
                break;
            case 9:
                if(IsEmpty()) printf("List is empty\n");
                else printf("List is not empty\n");
                break;
            default:
                printf("Invalid input,Try again...\n");
                break;
        }
    } while (a!=0);
}