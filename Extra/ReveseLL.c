#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}node;
void insert(node **start)
{
    int val;
    printf("Enter element: ");
    scanf("%d",&val);
    node *tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    if((*start)==NULL) (*start)=tmp;
    else
    {
        node *curr=(*start);
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=tmp;
    }
}
node *reverse(node *start)
{
    if(start==NULL || start->next==NULL) return start;
    node *curr=start,*prev=NULL,*nxt=NULL;
    while(curr!=NULL)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
    
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
void main()
{
    node *start=NULL;
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        insert(&start);
    }
    printf("List is: ");
    display(start);
    start=reverse(start);
    printf("Reverse list is: ");
    display(start);    
}