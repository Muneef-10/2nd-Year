// Q5
#include<iostream>
using namespace std;
struct node 
{
    int data;
    struct node* next;
};
typedef struct node node;

node *insert(node *head,int val)
{
    node* tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    if(head==NULL)
    head=tmp;
    else
    {
        node *tmp2=head;
        while(tmp2->next!=NULL)
        {
            tmp2=tmp2->next;
        }
        tmp2->next=tmp;
        tmp->next=NULL;
    }
    return head;
}

node *reverse(node *head)
{
    node *prev=NULL;
    node*curr=head;
    node*next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

node *recursionR(node *head)
{
    if(head==NULL | head->next==NULL)
    return head;
    node *Nhead=recursionR(head->next);
    node *f=head->next;
    f->next=head;
    head->next=NULL;
    return Nhead;
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
    node *head=NULL;
    head=insert(head,10);
    head=insert(head,15);
    head=insert(head,20);
    head=insert(head,25);
    head=insert(head,30);
    cout<<"Normal: ";
    display(head);

    cout<<"Reverse without recursion: ";
    head=reverse(head);
    display(head);

    cout<<"Again reverse using recursion";
    head=recursionR(head);
    display(head);
    return 0;
}