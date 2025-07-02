#include<iostream>
using namespace std;
struct node 
{
    int cons,exp;
    struct node *next;
};
typedef struct node node;

void CreateNode(node **head,int cons, int exp)
{
    node *tmp = (node*)malloc(sizeof(node));
    tmp->cons  = cons;
    tmp->exp  = exp;
    tmp->next = NULL;
    if (*head==NULL)
    {
        *head=tmp;
        return;
    }
    node * tmp2 = *head;
    while (tmp2!=NULL && tmp2->next!=NULL)
    {
        tmp2=tmp2->next;
    }
    
    tmp2->next = tmp;
}

void add(node *h1, node *h2, node **ans)
{
    while (h2!=NULL && h1!=NULL)
    {
        if(h1->exp > h2->exp)
        {
        CreateNode(ans,h1->cons,h1->exp);
        h1=h1->next;
        }
        else if (h1->exp < h2->exp)
        {
        CreateNode(ans,h2->cons,h2->exp);
        h2=h2->next;
        }
        else
        {
        CreateNode(ans,h1->cons+h2->cons,h1->exp);
        h1=h1->next;
        h2=h2->next;
        }
        
    }
    while (h1!=NULL)
    {
        CreateNode(ans,h1->cons,h1->exp);
        h1=h1->next;
    }
    while (h2!=NULL)
    {
        CreateNode(ans,h1->cons,h1->exp);
        h2=h2->next;
    }
}
void display(node *head)
{
    while (head!=NULL)
    {
        cout<<head->cons<<"x^"<<head->exp<<"  ";
        head=head->next;
    }
    cout<<endl;
}
int main()
{
    node *h1=NULL, *h2=NULL, *ans=NULL;
    CreateNode(&h1,3,3);
    CreateNode(&h1,2,2);
    CreateNode(&h1,1,1);
    CreateNode(&h1,-4,0);

    CreateNode(&h2,2,2);
    CreateNode(&h2,3,1);
    CreateNode(&h2,1,0);
    add(h1,h2,&ans);
    display(ans);

    return 0;
}