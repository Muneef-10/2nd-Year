//WAP to check a linked list is palindrome or not.
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
    int data;
    struct Node *next;
}node;
node *start=NULL;
node *start2=NULL;
node *create()
{
    int val;
    scanf("%d",&val);
    node *tmp=(node*)malloc(sizeof(malloc));
    tmp->next=NULL;
    tmp->data=val;
    return tmp;
}
void insert()
{
    node *temp=create();
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        node*curr=start;
        while(curr->next!=NULL) curr=curr->next;
        curr->next=temp;
    }
}
void reverse()
{
    start2=start;
    node*prev=NULL,*curr=NULL,*nxt=NULL;
    curr=start2;
    while(start2->next!=NULL) start2=start2->next;
    while(curr!=NULL)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }    
}
void display()
{
    node *tmp=start2;
    while(tmp!=NULL)
    {
        printf("%d",tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}
bool palindrome(int n)
{
    reverse();
    node *tmp=start;
    node *tmp2=start2;
    while(tmp!=NULL)
    {
        if(tmp->data!=tmp2->data)
        {
            return false;
        }
        tmp=tmp->next;
        tmp2=tmp2->next;
    }
    return true;
}
void main()
{
    int n;
    printf("Enter number of digit: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        insert();
    }
    display();
    if(palindrome(n)) printf("Palindrome\n");
    else printf("Not a palindrome");
}