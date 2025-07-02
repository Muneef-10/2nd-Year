#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node node;
void enqueue(node**head,node**last,int val)
{
    node* tmp=(node*)malloc(sizeof(node));
    tmp->info=val;
    tmp->next= NULL;
    if(*head==NULL)
    {
        *head=tmp;
        *last=tmp;
    } 
    else
    {
        (*last)->next=tmp;
        (*last)=tmp;
    }   
}
void dequeue(node**head,node**last)
{
    if((*head)==NULL) printf("Queue is empty\n");
    else
    {
        printf("\nDeleted value: %d\n",(*head)->info);
        (*head)=(*head)->next;
    }
}
void display(node *head)
{
    node *tmp=head;
    while(tmp!=NULL)
    {
        printf("%d ",tmp->info);
        tmp=tmp->next;
    }
}
int main()
{
    node *head=NULL,*last=NULL;
    enqueue(&head,&last,10);
    enqueue(&head,&last,15);
    enqueue(&head,&last,20);
    enqueue(&head,&last,25);
    display(head);

    dequeue(&head,&last);
    display(head);
    dequeue(&head,&last);
    display(head);
    return 0;
}