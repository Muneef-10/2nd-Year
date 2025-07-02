//Search an element in a list.
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}node;
node *start=NULL;
void insert(int val)
{
    node *tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    if(start==NULL) start=tmp;
    else
    {
        node *curr=start;
        while(curr->next!=NULL) curr=curr->next;
        curr->next=tmp;
    }
}
void search()
{
    int val,f=0;
    printf("Enter number: ");
    scanf("%d",&val);
    node *curr=start;
    while(curr!=NULL) 
    {
        if(curr->data==val) 
        {
            f=1;
            break;
        }
        curr=curr->next;
    }
    if(f==0) printf("Number not present\n");
    else printf("%d present in list\n",val);
}
void display()
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
    insert(10);
    insert(15);
    insert(20);
    insert(25);
    insert(30);
    insert(35);
    insert(40);
    display();
    search();
}