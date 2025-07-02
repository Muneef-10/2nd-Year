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
void middle(node *start)
{
    int c=0;
    node *curr=start;
    while(curr!=NULL)
    {
        c++;
        curr=curr->next;
    }
    curr=start;
    if(c%2!=0){
    for (int i = 0; i < c/2; i++)
    {
        curr=curr->next;
    }
    }
    else{
        for (int i = 1; i < (c/2); i++)
    {
        curr=curr->next;
    }
    }
    printf("%d",curr->data);
    
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
    printf("Middle node data is: ");
    middle(start);
    
}