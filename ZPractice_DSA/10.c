/*Design an algorithm and write a program to implement circular linked list. The program should implement following operations:
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
typedef struct node
{
    int data;
    struct node* next;
}node;
node *start=NULL;
node *create()
{
    int val;
    printf("Enter element: ");
    scanf("%d",&val);
    node *tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    return tmp;
}
void insertfront()
{
    node *tmp=create();
    tmp->next=start;
    start=tmp;
    node*curr=start->next;
    while(curr->next!=start->next) curr=curr->next;
    curr->next=tmp;
}
void dltfront()
{
    if(start==NULL) printf("No list found\n");
    else
    {
        node*curr=start;
        node*tmp=start;
        start=start->next;
        while(curr->next!=tmp) curr=curr->next;
        curr->next=start;
        tmp->next=NULL;
        free(tmp);
    }
}
void dltend()
{
    if(start==NULL) printf("No list found\n");
    else
    {
        node*curr=start;
        node*prev;
        while(curr->next!=start) 
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=start;
        curr->next=NULL;
        free(curr);

    }
}
void insertend()
{
    node *tmp=create();
    node*curr=start;
    while(curr->next!=start) curr=curr->next;
    curr->next=tmp;
    tmp->next=start;
}
void insertanywhere()
{
    int p;
    printf("Enter position: ");
    scanf("%d",&p);
    if(p==1) insertfront();
    else
    {
        node*tmp=create();
        node*curr=start;
        for (int i = 0; i < p-2; i++)
        {
            curr=curr->next;
        }
        tmp->next=curr->next;
        curr->next=tmp;
    }
}
void display()
{
    node* tmp=start;
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
        printf("Press [1] to create a list\n");
        printf("Press [2] to insert on first\n");
        printf("Press [3] to insert on last\n");
        printf("Press [4] to insert on anywhere\n");
        printf("Press [5] to delete from first\n");
        printf("Press [6] to delete from last\n");
        printf("Press [7] to delete from anywhere\n");
        printf("Press [0] for exit\n");
        scanf("%d",&a);
        switch(a)
        {
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
        }
    }while(a!=0);
}