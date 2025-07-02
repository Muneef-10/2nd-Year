#include<iostream>
using namespace std;
struct node
{
    int info;
    struct node *next;
};
void sorted(node **head,int val)
{
    node* tmp=(node*)malloc(sizeof(node));
    node* tmp2=(*head);
    tmp->info=val;
    tmp->next=NULL;
    if((*head)==NULL)
    {
    (*head)=tmp;
    }
    else if((*head)->next==NULL)
    {
        if((*head)->info > val)
        {
            tmp->next=(*head);
            (*head)=tmp;
        }
        else
        {
            (*head)->next=tmp;
        }
    }
    else if((*head)->info > val)
    {
        tmp->next=*head;
        *head=tmp;
    }
    else
    {
        while(tmp2->next!=NULL && tmp2->next->info < val)
        {
        tmp2 = tmp2->next;
        tmp->next = tmp2->next;
        tmp2->next = tmp;
        }
    }
}
void display(node *head)
{
    while(head!=NULL)
    {
        cout<<head->info<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main()
{
    node* head=NULL;
    sorted(&head,2);
    sorted(&head,20);
    sorted(&head,8);
    sorted(&head,4);
    sorted(&head,13);
    sorted(&head,17);
    display(head);
    return 0;
}