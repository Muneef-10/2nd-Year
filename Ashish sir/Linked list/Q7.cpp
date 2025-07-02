//Q2 fri
#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

node *insertFirst(node *head,int val)
{
    node*tmp=(node*)malloc(sizeof(node));
    tmp->data = val;
    if(head==NULL)
    {
        tmp->next=tmp;
        return tmp;
    }
    else
    {
        node *curr = head;
        while (curr->next!=head)
        {
            curr=curr->next;
        }
        tmp->next=head;
        curr->next = tmp;
        
    }
    return tmp;
}

node *insertLast(node *head,int val)
{
    node*tmp=(node*)malloc(sizeof(node));
    tmp->data = val;
    if(head==NULL)
        return insertFirst(head,val);
    else
    {
        node* curr = head;
        while (curr->next!=head)
        {
            curr=curr->next;
        }
        curr->next=tmp;
        tmp->next=head;
    }
    return head;
}

node *insertBtw(node *head,int val,int p)
{
    node*tmp=(node*)malloc(sizeof(node));
    tmp->data = val;
    if(head==NULL)
        return insertFirst(head,val);
    else
    {
        node* curr = head;
        for (int i = 0; i < p-1; i++)
        {
            curr=curr->next;
        }
        tmp->next=curr->next;
        curr->next=tmp;
        
    }
    return head;
}

void display(node *head)
{
    node*tmp=head;
    do
    {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    } while (tmp!=head);
    cout<<endl;
}
int main()
{
    node*head=NULL;
    head=insertFirst(head,10);
    head=insertFirst(head,15);
    head=insertFirst(head,20);
    head=insertFirst(head,25);
    cout<<"Normal insertion: ";
    display(head);

    head=insertLast(head,100);
    head=insertLast(head,200);
    cout<<"After insertion at last: ";
    display(head);

    head=insertBtw(head,148,2);
    cout<<"Insert '148' after position '2': ";
    display(head);

    return 0;
}