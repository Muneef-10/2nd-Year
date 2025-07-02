//LINKED LIST

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* add;
};
struct node* start=NULL,*tmp,*new1;
void create()
{
    char ch;
    int n;
    printf("Enter a element: ");
    scanf("%d",&n);
    start=(struct node*)malloc(sizeof(struct node));   //malloc function return type void ptr.  (In this it is explicit type casting(in this type-casting we convert void ptr into struct node ptr))
    start->data=n;
    start->add=NULL;
    // tmp=start;
    // printf("Want to continue if Yes enter 'y' if No enter 'n'..\n");
    // /*scanf("%c",&ch);*/  ch=getche();
    // while(ch=='y' || ch=='Y')
    // {
    //     printf("\nEnter next element: ");
    //     scanf("%d",&n);
    //     new1=(struct node*)malloc(sizeof(struct node));
    //     new1->data=n;
    //     new1->add=NULL;
    //     tmp->add=new1;
    //     tmp=tmp->add;
    //     printf("Want to continue if Yes enter 'y' if No enter 'n'..\n");
    //     ch=getche();
    // }
}

void InsertFirst()
{
    if(start==NULL) printf("List not found\n");
    else
    {
        int n;
        printf("Enter element: ");
        scanf("%d",&n);
        new1=(struct node *)malloc(sizeof(struct node));
        new1->data=n;
        new1->add=start;
        start=new1;
    }
}

void InsertLast()
{
    if(start==NULL) printf("List not found\n");
    else
    {
        int n;
        printf("Enter element: ");
        scanf("%d",&n);
        new1=(struct node *)malloc(sizeof(struct node));
        new1->data=n;
        new1->add=NULL;
        struct node *curr;
        curr=start;
        while(curr->add!=NULL)  curr=curr->add;
        curr->add=new1;
    }
}

void InMid()
{
    if(start==NULL) printf("List not found\n");
    else
    {
        int n,p;
        printf("Enter the position of new element: ");
        scanf("%d",&p);
        if(p==1)
            InsertFirst();
        else
        {
            printf("Enter element: ");
            scanf("%d",&n);
            struct node *curr;
            curr=start;
            for (int i = 0; i < p-2; i++)
            {
                curr=curr->add;
            }
            new1=(struct node*)malloc(sizeof(struct node));
            new1->data=n;
            new1->add=curr->add;
            curr->add=new1;        
        }
    }
}

void dltFirst()
{
    if(start==NULL) printf("No list found\n");
    else{
    tmp=start;
    start=start->add;
    printf("Deleted element: %d\n",tmp->data);
    free(tmp);    
    }
}

void dltLast()
{
    if(start==NULL) printf("No list found\n");
    else{
    struct node* curr;
    struct node* prev;
    curr=start;
    while(curr->add!=NULL)
    {
        prev=curr;
        curr=curr->add;
    }
    printf("Deleted element: %d\n",curr->data);
    prev->add=NULL;
    free(curr);
    }
}

void dltMid()
{
    if(start==NULL) printf("No list found\n");
    else
    {
        int p;
        printf("Enter position of element to delete that element: ");
        scanf("%d",&p);
        if(p==1) dltFirst();
        else{
        tmp=start;
        for(int i=0;i<p-2;i++)
        {
            tmp=tmp->add;
        }
        struct node *tmp2=tmp;
        tmp2=tmp2->add;
        printf("Deleted element: %d\n",tmp2->data);
        tmp->add=tmp2->add;
        free(tmp2);
        }
    }
}

void display()
{
    struct node *temp=start;
    if(start==NULL) printf("List not found\n");
    else
    {
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->add;
    }
    printf("\n");
    }
}
int size()
{
    if(start==NULL) printf("List not found");
    else{
    int c=0;
    tmp=start;
    while(tmp!=NULL)
    {
        c++;
        tmp=tmp->add;
    }
    return c;
    }
}
void midelement()
{
    if(size()%2==0) printf("Size of list is even\n");
    else
    {
        struct node *curr=start;
        for (int i = 0; i < size()/2; i++)
        {
            curr=curr->add;
        }
        printf("Middle element of the list is: %d",curr->data);        
    }
}
void IsEmpty()
{
    if(start==NULL) printf("List is empty");
    else printf("List is not empty");
}
void main()
{
    int n;
    do
    {
        printf("\n**********Linked List**********\n");
        printf("Press [1] to create a list\n");
        printf("Press [2] to insert on first\n");
        printf("Press [3] to insert on last\n");
        printf("Press [4] to insert on anywhere\n");
        printf("Press [5] to delete from first\n");
        printf("Press [6] to delete from last\n");
        printf("Press [7] to delete from anywhere\n");
        printf("Press [8] to check the size\n");
        printf("Press [9] to check list is empty or not\n");
        printf("Press [10] to find the middle element\n");
        printf("Press [0] for exit\n");
        printf("*******************************\n");

        scanf("%d",&n);
        switch(n)
        {
            case 0:
                printf("Exit..");
                break;
            case 1:
                create();
                break; 
            case 2:
                InsertFirst();
                display();
                break;
            case 3:
                InsertLast();
                display();
                break; 
            case 4:
                InMid();
                display();
                break; 
            case 5:
                dltFirst();
                display();
                break; 
            case 6:
                dltLast();
                display();
                break; 
            case 7:
                dltMid();
                display();
                break; 
            case 8:
                printf("Size of linked list is: %d\n",size());
                break; 
            case 9:
                IsEmpty();
                break; 
            case 10:
                midelement();
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    } while (n!=0);
    
}