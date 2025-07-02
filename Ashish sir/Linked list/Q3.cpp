#include<iostream>
using namespace std;
struct node
{
    int info;
    struct node *next;
};
void Enqueue(node **head, node **last, int v)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->info=v;
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;
        *last=temp;
    }
    else 
    {
        (*last)->next=temp;
        *last=temp;
    }
}
void display(node *head)
{
    while(head!=NULL)
    {
        cout<<head->info<<" ";
        head= head->next;
    }

}
node* Dequeue(node *head)
{
    if(head==NULL) 
    {
        cout<<"Queue is empty\n";
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
    node* head=NULL,*last=NULL;
    Enqueue(&head,&last,10);
    Enqueue(&head,&last,14);
    Enqueue(&head,&last,16);
    Enqueue(&head,&last,30);
    Enqueue(&head,&last,50);
    display(head);
    head=Dequeue(head);
    display(head);
    head=Dequeue(head);
    display(head);
    head=Dequeue(head);
    display(head);
    head=Dequeue(head);
    display(head);
    head=Dequeue(head);
    display(head);
    head=Dequeue(head);
    display(head);
    head=Dequeue(head);
    display(head);

    return 0;
}