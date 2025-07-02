//Q3
#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node node;

node *insertFirst(node *head,int val)
{
    node *tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->prev=NULL;
    tmp->next=NULL;
    if(head==NULL)
    {
        head=tmp;
        head->next=head;
        head->prev=head;
    }
    else
    {
        head->prev->next=tmp;
        tmp->prev=head->prev;
        tmp->next=head;
        head->prev=tmp;
        head=tmp;
    }
    return tmp;
}

node* insertLast(node*head,int val)
{
    node *tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    tmp->prev=NULL;
    if(head==NULL)
    return insertFirst(head,val);
    else
    {
        node *tmp2=head;
        while(tmp2->next!=head)
        {
            tmp2=tmp2->next;
        }
        tmp->next=tmp2->next;
        tmp->prev=tmp2;
        tmp2->next->prev=tmp;
        tmp2->next=tmp;
    }
    return head;
}

node* insertBtw(node*head,int val,int p)
{
    node *tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    tmp->prev=NULL;
    if(head==NULL)
    return insertFirst(head,val);
    else
    {
        node *tmp2=head;
        for(int i=0;i<p-1;i++)
        {
            tmp2=tmp2->next;
        }
        tmp->next=tmp2->next;
        tmp2->next->prev=tmp;
        tmp2->next=tmp;
        tmp->prev=tmp2;
    }
    return head;
}

void display(node *head)
{
    node *tmp2=head;
    do
    {
        cout<<tmp2->data<<" ";
        tmp2=tmp2->next;
    } while (tmp2!=head);
    cout<<endl;
}
int main()
{
    node *head=NULL;
    head=insertFirst(head,10);
    head=insertFirst(head,15);
    head=insertFirst(head,20);
    head=insertFirst(head,25);
    cout<<"Normal insertion: ";
    display(head);

    head=insertLast(head,100);
    head=insertLast(head,200);
    head=insertLast(head,300);
    cout<<"After insertion at last: ";
    display(head);

    head=insertBtw(head,297,1);
    cout<<"Insert '297' after position '1'";
    display(head);
    return 0;
}
