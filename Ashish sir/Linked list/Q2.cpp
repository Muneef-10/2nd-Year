#include<iostream>
using namespace std;
struct node
{
    int info;
    struct node *next;
};

node *push(node *head, int val)
{
    node *temp= (node*)malloc(sizeof(node));
    temp->info=val;
    temp->next= head;
    head=temp;
    return head;
}

node *pop(node *head)
{
    node *temp=head;
    head = head->next;
    temp->next = NULL;
    cout<<"Deleted value: "<<temp->info<<endl;
    free(temp);
    return head;
}

void insertbtw(node *head,int val, int a)
{
    node *temp = head;
    node *abc = (node *)malloc(sizeof(node));
    abc->info = val;
    while (temp->info!=a)
    {
        temp=temp->next;
    }
    abc->next = temp->next;
    temp->next = abc;
}

void insertlst(node *head, int val)
{
    node *temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    node *abc = (node *)malloc(sizeof(node));
    abc->info=val;
    abc->next = NULL;
    temp->next = abc;
}

void display(node *head)
{
    while(head != NULL)
    {
        cout<<head->info<<" ";
        head = head->next;
    }
    cout<<endl;
}
typedef struct node node;
int main()
{
    node *head = NULL;
    int n=0;
    head = push(head,10);
    head = push(head,15);
    head = push(head,20);
    head = push(head,25);
    head = push(head,30);
    display(head);
    head=pop(head);
    display(head);
    cout<<"Enter number from stack: ";
    cin>>n;
    cout<<"Inserting 35 after "<<n<<endl;
    insertbtw(head,35,n);
    display(head);
    cout<<"Inserting 100 at last"<<endl;
    insertlst(head, 100);
    display(head);

    return 0;
}