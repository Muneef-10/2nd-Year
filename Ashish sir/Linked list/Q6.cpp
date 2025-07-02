//Q1 all part fri
#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node node;

node *insertFirst(node *head,int val)
{
    node*tmp=(node*)malloc(sizeof(node));
    tmp->data = val;
    tmp->next = NULL;
    tmp->prev=NULL;
    if(head==NULL)
        head=tmp;
    else
    {
        tmp->next=head;
        head->prev=tmp;
        head=tmp;
    }
    return head;
}

node *insertLast(node *head,int val)
{
    node*tmp=(node*)malloc(sizeof(node));
    tmp->data = val;
    tmp->next = NULL;
    tmp->prev=NULL;
    if(head==NULL)
        head=tmp;
    else
    {
        node* curr = head;
        while (curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=tmp;
        tmp->prev=curr;
    }
    return head;
}

node *insertBtw(node *head,int val,int p)
{
    node*tmp=(node*)malloc(sizeof(node));
    tmp->data = val;
    tmp->next = NULL;
    tmp->prev=NULL;
    if(head==NULL)
        head=tmp;
    else
    {
        node* curr = head;
        for (int i = 0; i < p-1; i++)
        {
            curr=curr->next;
        }
        tmp->next=curr->next;
        curr->next->prev=tmp;
        tmp->prev=curr;
        curr->next=tmp;
        
    }
    return head;
}

void display(node *head)
{
    node *tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}

int main()
{
    node* head=NULL;
    head=insertFirst(head,10);
    head=insertFirst(head,15);
    head=insertFirst(head,20);
    head=insertFirst(head,25);
    cout<<"Normal insertion: ";
    display(head);

    head = insertLast(head,100);
    head = insertLast(head,200);
    cout<<"After insertion at last: ";
    display(head);

    insertBtw(head,56,3);
    cout<<"Insert '56' after position '3': ";
    display(head);

    return 0;
}