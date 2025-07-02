#include<bits/stdc++.h>
using namespace std;
struct node
{
    int info;
    struct node *next;
};
typedef struct node node;

void sorted(node **head, int val)
{
    node *tmp=*head;
    node *tmp2 = (node*)malloc(sizeof(node));
    tmp2->info = val;
    tmp2->next = NULL;
    if(*head==NULL||(*head)->info >= val)
    {
        tmp2->next = *head;
        *head = tmp2;
        return ;
    }
    while(tmp!=NULL && tmp->next!=NULL && tmp->next->info < val)
    {
        tmp = tmp->next;
    }

    tmp2->next = tmp->next;
    tmp->next = tmp2;
}
void dlt(node **head, int key)
{
    
    if(*head == NULL)
    {
        cout<<key<<" not found"<<endl;
        return;
    }

    node *tmp = *head;
    if(tmp->info==key)
    {
        *head = tmp->next;
        free(tmp);
        return;
    }

    while(tmp->next != NULL && tmp->next->info!=key)
    {
        tmp = tmp->next;
    }
    if(tmp->next==NULL)
    {
        cout<<key<<" not found"<<endl;
        return;
    }

    node *tmp2 = tmp->next;
    tmp->next = tmp2->next;
    tmp2->next = NULL;
    free(tmp2);
}
void display(node *head)
{
    while(head!=NULL)
    {
        cout<<head->info<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main()
{
    node *head = NULL;
    int a[] = {20,5,15,9,7,10};
    cout<<"List is:  ";
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        sorted(&head,a[i]);
    }
    
    display(head);
    dlt(&head,20);
    dlt(&head,15);
    dlt(&head,6);
    dlt(&head,7);   
    display(head);    

    return 0;
}