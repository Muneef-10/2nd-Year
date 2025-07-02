// printf("Press [1] to create a list\n");
// printf("Press [2] to insert on first\n");
// printf("Press [3] to insert on last\n");
// printf("Press [4] to insert on anywhere\n");
// printf("Press [5] to delete from first\n");
// printf("Press [6] to delete from last\n");
// printf("Press [7] to delete from anywhere\n");
// printf("Press [8] to check the size\n");
// printf("Press [9] to check list is empty or not\n");
// printf("Press [10] to find the middle element\n");
// printf("Press [0] for exit\n");

#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}node;
node *start=NULL;
node* create()
{
    int val;
    printf("Enter element: ");
    scanf("%d",&val);
    node *tmp=(node *)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    return tmp;
}
void insertfront()
{
    node *tmp=create();
    tmp->next=start;
    start=tmp;
}
void insertend()
{
    node *tmp=create();
    node *curr=start;
    while(curr->next!=NULL) curr=curr->next;
    curr->next=tmp;
}
void insertanywhere()
{
    int p;
    printf("Enter position: ");
    scanf("%d",&p);
    if(p==1) 
    {
        insertfront();
        return ;
    }
    node *tmp=create();
    node *curr=start;
    for (int i = 0; i <p-2; i++)
    {
        curr=curr->next;
    }
    tmp->next=curr->next;
    curr->next=tmp;
}
void dltfront()
{
    if(start==NULL)  printf("No list found\n");
    else{
    node *tmp=start;
    printf("Deleted element: %d",start->data);
    start=start->next;
    tmp->next=NULL;
    free(tmp);
    }
}
void dltend()
{
    if(start==NULL)  printf("No list found\n");
    else{
    node *prev=NULL,*curr=start;
    while(curr->next!=NULL) 
    {
        prev=curr;
        curr=curr->next;
    }
    printf("Deleted element: %d",curr->data);
    prev->next=NULL;
    free(curr);
    }
}
void dltanywhere()
{
    int p;
    printf("Enter position: ");
    scanf("%d",&p);
    if(p==1) dltfront();
    else{
        node *curr=start;
        for (int i = 0; i < p-2; i++)
        {
            curr=curr->next;
        }
        node *tmp=curr->next;
        printf("Deleted element: %d",tmp->data);
        curr->next=tmp->next;
        tmp->next=NULL;
        free(tmp);       
    }
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
        }
    }while(a!=0);
}