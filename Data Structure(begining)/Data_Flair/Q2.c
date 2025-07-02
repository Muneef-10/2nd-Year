#include<stdio.h>
#include<stdbool.h>
void enqueue(int q[],int s,int *f,int *r)
{
    if((*r)==s-1) printf("Queue is full\n");
    else
    {
        int a;
        printf("Enter element: ");
        scanf("%d",&a);

        if((*f)==-1) (*f)=0;
        (*r)++;
        q[*r]=a;
    }
}

int dequeue(int q[],int *f,int *r)
{
    int k=-1;
    if((*f)==-1) 
    {
        printf("Queue is empty\n");
    }
    else
    {
        k=q[*f];
        (*f)++;
        if((*f)>(*r)) (*f)=(*r)=-1;
    }
    return k;
}
bool IsEmpty(int f)
{
    return f==-1;
}
void size(int r)
{
    printf("Size of the queue is: %d\n",r+1);
}
void display(int q[],int f,int r)
{
    if(f==-1) printf("Queue is empty\n");
    else
    {
        for (int i = f; i <= r; i++)
        {
            printf("%d ",q[i]);
        }
        printf("\n");
        
    }
}
void main()
{
    int r=-1,f=-1,n,s,x;
    printf("Enter the size of an array: ");
    scanf("%d",&s);
    int q[s];
    do
    {
        printf("Press [1] for enqueue\n");
        printf("Press [2] for dequeue\n");
        printf("Press [3] for display\n");
        printf("Press [4] to check queue is empty or not\n");
        printf("Press [5] to check the size of queue\n");
        printf("Press [0] for exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 0:
                printf("Exit..");
                break;
            case 1:
                enqueue(q,s,&f,&r);
                break;
            case 2:
                x=dequeue(q,&f,&r);
                printf("Deleted element: %d\n",x);
                break;
            case 3:
                display(q,f,r);
                break;
            case 4:
                if(IsEmpty(f)) printf("Queue is empty\n");
                else printf("Queue is not empty\n");
                break;
            case 5:
                size(r);
                break;
            default:
                printf("Invalid input");
                break;
        }
    }while(n!=0);
}