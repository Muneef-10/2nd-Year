#include<iostream>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *next;
} node;
node *start=NULL;
void insert(int val)
{
    node *tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    if (start==NULL) start=tmp;
    else if(start->next==NULL)
    {
        if(val > start->data)
        {
            start->next=tmp;
        }
        else
        {
            tmp->next=start;
            start=tmp;
        }
    }
    else 
    {
        if(val < start->data )
        {
            tmp->next=start;
            start=tmp;
        }
        else
        {
            node* curr=start;
            while (curr->next!=NULL && curr->next->data < tmp->data) curr=curr->next;
            // if(curr->next!=NULL)
            // {
                tmp->next=curr->next;
                curr->next=tmp;
            // }
            // else curr->next=tmp;
        }
    }
}
void display()
{
    node *tmp=start;
    while(tmp!=NULL)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}
int main()
{
    insert(10);
    insert(8);
    insert(12);
    insert(18);
    insert(16);
    insert(11);
    insert(5);
    display();
    return 0;
}