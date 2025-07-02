#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *add;
};
typedef struct node node;
node *start=NULL,*last=NULL;
// void InsertLast()
// {
//     int n;
//     printf("Enter element in list: ");
//     scanf("%d",&n);
//     node* tmp=(node*)malloc(sizeof(node));
//     tmp->data=n;
//     tmp->add=NULL;
//     if(start==NULL)
//     {
//         start=tmp;
//         last=tmp;
//     }
//     else
//     {
//         last->add=tmp;
//         last=tmp;
//     }    
// }
void InsertLast()
{
    int n;
    printf("Enter element in list: ");
    scanf("%d",&n);
    node* tmp=(node*)malloc(sizeof(node));
    tmp->data=n;
    tmp->add=NULL;
    if(start==NULL)
    {
        start=tmp;
    }
    else{
    node *curr=start;
    while(curr->add!=NULL) curr=curr->add;
    curr->add=tmp;
    }
}
void display()
{
    struct node *temp=start;
    if(start==NULL) printf("List not found\n");
    else
    {
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->add;
    }
    printf("\n");
    }
}
void search()
{
    int n,f=0;
    printf("Enter element to search: ");
    scanf("%d",&n);
    node *curr;
    curr=start; 
    while(curr!=NULL)
    {
        if(curr->data==n)
        {
            f=1;
            break;
        }
        curr=curr->add;
    }
    if(f==1) printf("%d is present in list",n);
    else printf("%d is not present in list",n);
}
void main()
{
    InsertLast();
    InsertLast();
    InsertLast();
    InsertLast();
    InsertLast();
    display();
    search();
}