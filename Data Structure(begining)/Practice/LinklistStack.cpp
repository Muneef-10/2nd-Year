#include<iostream>
using namespace std;
struct node 
{
    int info;
    struct node *next;
};
typedef struct node node;
node* push(node *head, int val)
{
    node* tmp=(node *)malloc(sizeof(node));
    tmp->info=val;
    tmp->next=head;
    head=tmp;
    return head;
}
void peek(node*head)
{
    if(head==NULL) cout<<"Stack is empty\n";
    else
    {
        cout<<"\nTopmost element is: "<<head->info<<endl;
    }
}
void display(node*head)
{
    while(head!=NULL)
    {
        cout<<head->info<<" ";
        head= head->next;
    }
}
node* pop(node *head) 
{
    if(head==NULL) cout<<"Stack is empty";
    else 
    {
        node* tmp=head;
        head=head->next;
        tmp->next=NULL;
        cout<<"\nDeleted element: "<<tmp->info<<endl;
        // head=head->next;
        free(tmp);
        return head;
    }
}
int main()
{
    node* head=NULL;
    head=push(head,10);
    head=push(head,15);
    head=push(head,20);
    head=push(head,25);
    head=push(head,30);
    head=push(head,35);
    display(head);
    peek(head);
    head=pop(head);
    display(head);
    head=pop(head);
    display(head);
    head=pop(head);
    display(head);
    return 0;
}