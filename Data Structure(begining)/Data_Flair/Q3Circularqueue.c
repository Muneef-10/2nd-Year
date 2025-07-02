#include<stdio.h>
#include<conio.h>

#define SIZE 5
int cq[SIZE],r=-1,f=-1;

void enqueue()
{
    //if((f==0 && r==SIZE-1) || r==f-1) printf("Queue is full\n");
    if(((r+1)%SIZE)==f) printf("Queue is full\n");
    else 
    {
        int a;
        printf("Enter element: ");
        scanf("%d",&a);
        // if(f==-1) f=0;
        // r=(r+1)%SIZE;
        // cq[r]=a;
        if(f==-1 && r==-1)
        {
            f=0;
            r=0;
        } 
        else r=(r+1)%SIZE;
        cq[r]=a;
    }
}

void dequeue()
{
    if(f==-1) printf("Queue is empty\n");
    else
    {
        printf("Deleted element: %d\n",cq[f]);
        if(f==r)
        {
            f=-1;
            r=-1;
        } 
        else f=(f+1)%SIZE;

    }
}

void display()
{
    if(f==-1) printf("Queue is empty\n");
    else
    {
        int i=f;
    do
    {
        printf("%d ",cq[i]);
        i=(i+1)%SIZE;
    }while(i!=(r+1)%SIZE);
    //printf("%d\n",cq[i]);
    printf("\n");
    }
}
void main()
{
    int n;
    do
    {
        printf("Press [1] for enqueue\n");
        printf("Press [2] for dequeue\n");
        printf("Press [3] for display\n");
        printf("Press [0] for exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 0:
                printf("Exit..");
                break;
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    }while(n!=0);
}
