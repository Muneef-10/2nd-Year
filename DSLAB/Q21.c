#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
    int data;
    struct Node* next;
}node;
typedef struct Stack
{
    node* top;
}stack;
void initializestack(stack *st)
{
    (st)->top=NULL;
}
node *createnode()
{
    int val;
    printf("Enter element: ");
    scanf("%d",&val);
    node* tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    return tmp;
}
void push(stack **st)
{
    node* tmp=createnode();
    tmp->next=(*st)->top;
    (*st)->top=tmp;
}
int pop(stack *st)
{
    if((st)->top==NULL)
    {
        printf("Stack is empty\n");
        return 0;
    }
    else{
    node*tmp=(st)->top;
    (st)->top=tmp->next;
    int v=tmp->data;
    tmp->next=NULL;
    free(tmp);
    return v;
    }
}
bool IsEmpty(stack *st)
{
    return st->top==NULL;
}
void display(stack *st)
{
    node* tmp=(st)->top;
    while(tmp!=NULL)
    {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}
void size(stack *st)
{
    int c=0;
    node* tmp=st->top;
    while(tmp!=NULL)
    {
        c++;
        tmp=tmp->next;
    }
    printf("Size of stack is :%d\n",c);
}
int main()
{
    stack *st=(stack*)malloc(sizeof(stack));
    initializestack(st);
    int a;
    do
    {
        printf("press [1] to create\n");
        printf("press [2] to push\n");
        printf("press [3] to pop\n");
        printf("press [4] to check stack is empty or not\n");
        printf("press [5] to check size\n");
        printf("press [0] to exit\n");
        scanf("%d",&a);
        switch(a)
        {
            case 0:
                printf("Exit..");
                break;
            case 1:
                st->top=createnode();
                break;
            case 2:
                push(&st);
                display(st);
                break;
            case 3:
                pop(st);
                display(st);
                break;
            case 4:
                if(IsEmpty(st)) printf("Stack is empty\n");
                else printf("Stack is not empty\n");
                break;
            case 5:
                size(st);
                break;
            default:
                printf("Invalid input,Try again...\n");
                break;
        }
    }while(a!=0);  
    return 0;
}