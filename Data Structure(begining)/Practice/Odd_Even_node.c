//Given the head of single linked list group all the node odd indices together followed by node with even indices. The first node is considered as odd .Donot change the order b/w odd and even groups.
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}node;

void insert(node **start)
{
    int val;
    printf("Enter value: ");
    scanf("%d",&val);
    node*tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    if((*start)==NULL)
    {
        (*start)=tmp;
    }
    else
    {
        node *curr=(*start);
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=tmp;
    }
}
void split(node **start,node **start2,node **start3)
{
    node *tmp=(*start);
    int c=0;
    while(tmp!=NULL)
    {
        c++;
        if(c%2==0)
        {
            node *tmp2=tmp;
            tmp=tmp->next;
            tmp2->next=NULL;
            if((*start2)==NULL)
            (*start2)=tmp2;
            else
            {
                node *curr2=(*start2);
                while(curr2->next!=NULL) curr2=curr2->next;
                curr2->next=tmp2;
            }
        }
        else
        {
            node *tmp2=tmp;
            tmp=tmp->next;
            tmp2->next=NULL;
            if((*start3)==NULL)
            (*start3)=tmp2;
            else
            {
                node *curr2=(*start3);
                while(curr2->next!=NULL) curr2=curr2->next;
                curr2->next=tmp2;
            }
        }
    }
}
void display(node *start)
{
    node *tmp=start;
    while(tmp!=NULL)
    {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}
void main()
{
    int a;
    node *start=NULL,*start2=NULL,*start3=NULL;
    do
    {
        printf("Press [1] for insert\n");
        printf("Press [2] for display\n");
        printf("Press [0] for Exit\n");
        scanf("%d",&a);
        switch(a)
        {
            case 0:
                printf("Exit..");
                break;
            case 1:
                insert(&start);
                break;
            case 2:
                printf("Original List: ");
                display(start);
                split(&start,&start2,&start3);
                printf("Odd numbered nodes List: ");
                display(start3);
                printf("Even numbered nodes List: ");
                display(start2);
                break;
            default:
                printf("wrong input,try again..");
                break;
        }
    }while(a!=0);
}