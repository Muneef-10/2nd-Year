/*WAP to implement singly linklist.the program should implement following operations
Create();- create linklist single node of value k;
insertfront():- insert value k in the front of link list.
insertend():- insert value k at the end of link list.
insertanywhere():-insert anuwhere at position p.*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
typedef struct node node;
node* create()
{
    int val;
    printf("Enter a value: ");
    scanf("%d",&val);
    node* tmp=(node *)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    return tmp;
}
void insertfront(node** head)
{
    node* tmp=create();
    tmp->next=(*head);
    (*head)=tmp;
    return;
}
void insertend(node **head,node **last)
{
    node* tmp=create();
    node *curr=*head;
    while(curr->next!=NULL) curr=curr->next;
    curr->next=tmp;
    return ;
}
node* dltfront(node *head) 
{
    if(head==NULL) printf("Stack is empty\n");
    else 
    {
        node* tmp=head;
        head=head->next;
        tmp->next=NULL;
        printf("\nDeleted element: %d\n",tmp->data);
        free(tmp);
        return head;
    }
}
node* dltend(node *head) 
{
    if(head==NULL) printf("Stack is empty\n");
    else 
    {
        node *curr=head;
        while(curr->next!=NULL) curr=curr->next;
        // curr->next=NULL;
        printf("\nDeleted element: %d\n",curr->data);
        free(curr);
        return head;
    }
}
void display(node*head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head= head->next;
    }
    printf("\n");
}
void main()
{
    int a;
    node *head=NULL,*last=NULL;
    do
    {
        printf("press [1] to create a link list\n");
        printf("press [2] to insert in front in a link list\n");
        printf("press [3] to insert at end in a link list\n");
        //printf("press [4] to insert at position 'P' in  a link list\n");
        printf("press [4] to dlt at front\n");
        printf("press [5] to dlt at end\n");
        printf("press [6] to display\n");
        printf("press [0] to exit\n");
        scanf("%d",&a);
        switch(a)
        {
            case 0:
                printf("Exit..");
                break;
            case 1:
                head=create();
                break;
            case 2:
                insertfront(&head);
                break;
            case 3:
                insertend(&head,&last);
                break;
            case 4:
                head=dltfront(head);
                break;
            case 5:
                head=dltend(head);
                break;
            case 6:
                display(head);
                break;
            default:
                printf("Invalid input,Try again...");
                break;
        }
    } while (a!=0);
    
}