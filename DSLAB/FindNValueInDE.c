//Find value of n'th node of LL.DOUBLE LL.
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *Next;
    struct Node *prev;
}node;
node *create()
{
    int val;
    printf("Enter value: ");
    scanf("%d",&val);
    node *tmp=(node *)malloc(sizeof(node));
    tmp->data=val;
    tmp->Next=NULL;
    tmp->prev=NULL;
    return tmp;
}
void insert(node **start)
{
    if(*start==NULL) *start=create();
    else
    {
        node *tmp=create();
        node *curr=(*start);
        while(curr->Next!=NULL) curr=curr->Next;
        curr->Next=tmp;
        tmp->prev=curr;
    }
}
void display(node *start)
{
    node *tmp=start;
    while (tmp!=NULL)
    {
        printf("%d ",tmp->data);
        tmp=tmp->Next;
    }
    printf("\n");
}

void main()
{
    node *start=NULL;
    int n,k;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        insert(&start);
    }
    printf("Enter node number for their value: ");
    scanf("%d",&k);
    node *curr=start;
    for (int i = 0; i < k-1; i++)
    {
        curr=curr->Next;
    }
    printf("Linked List: ");
    display(start);
    printf("Value of node number %d is: %d",k,curr->data);
    
    
}