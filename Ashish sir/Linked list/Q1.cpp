#include<iostream>
using namespace std;
struct node
{
    int info;
    struct node *next;
};
node* push(node *head, int val)
{
    if(head==NULL)
    {
        head=(node *)malloc(sizeof(node));
        head->info=val;
        head->next=NULL;
        return head;
    }
    else
    {
        node* tmp=(node *)malloc(sizeof(node));
        tmp->info=val;
        tmp->next=head;
        head=tmp;
        return tmp;
    }
}
void display(node *head)
{
    while(head!=NULL)
    {
        cout<<head->info<<" ";
        head = head->next;
    }

}
node* pop(node *head)
{
    if(head==NULL) 
    {
        cout<<"Stack is empty\n";
        return NULL;
    }
    node* temp=head;
    head=head->next;
    temp->next=NULL;
    cout<<"\nDeleted value: "<<temp->info<<endl;
    return head;
}
typedef struct node node;
int main()
{
    node* head=NULL;
    head=push(head,13);
    head=push(head,-45);
    head=push(head,87);
    head=push(head,20);
    head=push(head,18);
    display(head);
    head=pop(head);
    display(head);
    head=pop(head);
    display(head);
    head=pop(head);
    display(head);
    head=pop(head);
    display(head);
    head=pop(head);
    display(head);
    head=pop(head);
    display(head);
    
    return 0;
}