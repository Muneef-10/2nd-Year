// Assuming that you have two single linked lists, pointers P1 and p2. are pointing to the first node of the linked lists respectively, Write a C function to print the addition of the data in the given linked lists.
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}node;
void insert(node **ptr,int val)
{
    node *tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    if(*ptr==NULL) *ptr=tmp;
    else 
    {
        node*curr=*ptr;
        while(curr->next!=NULL) curr=curr->next;
        curr->next=tmp;
    }
}
void add(node *ptr1,node *ptr2)
{
    node*tmp1=ptr1;
    node*tmp2=ptr2;
    while(tmp1!=NULL && tmp2!=NULL)
    {
        tmp1->data=tmp1->data+tmp2->data;
        tmp1=tmp1->next;
        tmp2=tmp2->next;
    }
    tmp1=ptr1;
    while(tmp1!=NULL)
    {
        printf("%d ",tmp1->data);
        tmp1=tmp1->next;
    }
    printf("\n");
}
// void display(node *ptr)
// {
//     node* tmp=ptr;
//     while(tmp!=NULL )
//     {
//         printf("%d ",tmp->data);
//         tmp=tmp->next;
//     }
// }
void main()
{
    node* ptr1=NULL;
    node* ptr2=NULL;
    insert(&ptr1,12);
    insert(&ptr1,13);
    insert(&ptr1,14);
    insert(&ptr1,15);
    insert(&ptr1,7);

    insert(&ptr2,3);
    insert(&ptr2,14);
    insert(&ptr2,15);
    insert(&ptr2,12);
    insert(&ptr2,16);
    // printf("1st linked list: ");
    // display(ptr1);
    // printf("2nd linked list: ");
    // display(ptr2);
    add(ptr1,ptr2);
}