/*Rotate a linked list in 'K' times
eg:-1 2 3 4 5 
k=2
3 4 5 1 2 Placement class exam question*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}node;
node *create(node *head)
{
    int  val;
    printf("Enter number: ");
    scanf("%d",&val);
    head=(node*)malloc(sizeof(node));
    head->data=val;
    head->next=NULL;
    return head;
}
node* rotate(node**head,int k)
{
    node *temp=(*head);
    node *curr=(*head);
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    temp=(*head);
    k=k%count;
    for (int i = 0; i < k; i++)
    {
        (*head)=(*head)->next;
    }
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }    
    for (int i = 0; i < k; i++)
    {
        curr->next=temp;
        curr=curr->next;
        temp=temp->next;
        curr->next=NULL;
    }
    return (*head);
}
void main()
{
    node *head=NULL;
    node *temp=NULL;
    int n,k;
    printf("Enter size of linked list: ");
    scanf("%d",&n);
    head=temp=create(head);
    for (int i = 1; i < n; i++)
    {
        temp->next=create(temp);
        temp=temp->next;
    }
    printf("Enter 'K: ");
    scanf("%d",&k);
    temp=rotate(&head,k);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
}