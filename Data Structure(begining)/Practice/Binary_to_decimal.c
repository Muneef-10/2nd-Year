//Given a head of a single linked list find the decimal value of no.represented by linked list. the value of each node is either 0 or 1.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Node
{
    int data;
    struct Node *next;
}node;
node *start=NULL;
node *create()
{
    int val;
    scanf("%d",&val);
    node *tmp=(node*)malloc(sizeof(malloc));
    tmp->next=NULL;
    tmp->data=val;
    return tmp;
}
void insert()
{
    node *temp=create();
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        node*curr=start;
        while(curr->next!=NULL) curr=curr->next;
        curr->next=temp;
    }
}
void display()
{
    node *tmp=start;
    while(tmp!=NULL)
    {
        printf("%d",tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}
int calculate(int n)
{
    node *tmp=start;
    int sum=0,x=n-1;
    for (int i = 0; i < n; i++)
    {
        sum=sum+(tmp->data*pow(2,x));
        tmp=tmp->next;
        x--;
    }
    return sum;
}
void main()
{
    int n;
    printf("Enter number of digit: ");
    scanf("%d",&n);
    printf("Enter number:\n");
    for (int i = 0; i < n; i++)
    {
        insert();
    }
    printf("Binary number is: ");
    display();
    printf("Decimal number is: %d",calculate(n));
}