//Q4
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};
typedef struct node node;
node* insert(node* head,int val)
{
    node* tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    if(head==NULL) {
        head=tmp;
        head->next=head;
    }
    else{
        node* tmp2=head;
        while(tmp2->next!=head)
        {
            tmp2=tmp2->next;
        }
        tmp2->next=tmp;
        tmp->next=head;
    }
    return head;
}

bool detect (node* head)
{
    if(head==NULL || head->next==head)
    return true;
    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    node* head=NULL;
    head=insert(head,10);
    head=insert(head,15);
    head=insert(head,20);
    head=insert(head,25);

    if(detect(head)) cout<<"yes it is a cycle";
    else cout<<"Not a cycle";
}