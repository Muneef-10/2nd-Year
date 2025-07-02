/* Write an algorithm and a program to implement doubly linked list. The program should implement following operations:
a) Create(k) - create a doubly linked list node with value k.
b)InsertFront(k) - insert node at the front of the linked list.
c) InsertEnd(k) - insert a node at the end of the linked list.
d)InsertIntermediate(k,p) - insert a node at specific position p.
e) DeleteFront() - delete a node from the front of the linked list.
f) DeleteEnd() - delete a node from the end of the linked list.
g)DeleteIntermediate(p) – delete a node from a specific position p.
h)Size() - returns the size of doubly linked list.
i) IsEmpty() - checks whether the list is empty or not.
j) FindMiddle() - returns the contents of middle node of the list.*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next,*prev;
}node;
node *start=NULL;
node *create()
{
    node* tmp=(node*)malloc(sizeof(node));
    int val;
    printf("Enter element: ");
    scanf("%d",&val);
    tmp->data=val;
    tmp->prev=NULL;
    tmp->next=NULL;
    return tmp;
}
void insertfront()
{
    node *tmp=create();
    // if(start==NULL) start=tmp;
    // else
    // {
        tmp->next=start;
        start->prev=tmp;
        start=tmp;
    //}
}
void insertend()
{
    node *tmp=create();
    node *curr=start;
    while(curr->next!=NULL) curr=curr->next;
    curr->next=tmp;
    tmp->prev=curr;
}
void insertanywhere()
{
    int p;
    printf("Enter position: ");
    scanf("%d",&p);
    if(p==1) insertfront();
    else
    {
        node *tmp=create();
        node *curr=start;
        for (int i = 0; i < p-2; i++)
        {
            curr=curr->next;
        }
        tmp->next=curr->next;
        curr->next->prev=tmp;
        curr->next=tmp;
        tmp->prev=curr;        
    }
}
void dltfront()
{
    if(start==NULL) printf("List not found\n");
    else
    {
        node*tmp=start;
        start=start->next;
        start->prev=NULL;
        printf("Deleted value: %d\n",tmp->data);
        tmp->next=NULL;
        free(tmp);
    }
}
void dltend()
{
    if(start==NULL) printf("List not found\n");
    else
    {
        node*curr=start;
        while(curr->next!=NULL) curr=curr->next;
        printf("Deleted value: %d\n",curr->data);
        curr->prev->next=NULL;
        curr->prev=NULL;
        free(curr);
    }
}
void dltanywhere()
{
    if(start==NULL) printf("List not found\n");
    else
    {
        int p;
        printf("Enter position: ");
        scanf("%d",&p);
        if(p==1) dltfront();
        else
        {
            node*curr=start;
            for (int i = 0; i < p-2; i++)
            {
                curr=curr->next;
            }
            node*tmp=curr->next;
            tmp->next->prev=tmp->prev;
            curr->next=tmp->next;
            printf("Deleted value: %d\n",tmp->data);
            tmp->next=NULL;
            tmp->prev=NULL;
            free(tmp);
        }
    }
}
void display()
{
    node*tmp=start;
    while(tmp!=NULL)
    {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}
void size()
{
    int c=0;
    node*tmp=start;
    while(tmp!=NULL)
    {
        c++;
        tmp=tmp->next;
    }
    printf("Size: %d\n",c);
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
        printf("Press [8] to check the size\n");
        printf("Press [9] to check list is empty or not\n");
        printf("Press [10] to find the middle element\n");
        printf("Press [0] for exit\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                start=create();
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
                size();
                display();
                break;
        }
    } while (a!=0);
    
}