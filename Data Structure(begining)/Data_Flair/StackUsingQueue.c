#include<stdio.h>
void enqueue(int q[],int *f,int *r,int val)
{
    if(*f==-1) *f=0;
    (*r)++;
    q[*r]=val;
}
int dequeue(int q[],int *f,int *r)
{
    int d=q[*f];
    if(*f==*r) *f=*r=-1;
    else (*f)++;
    return d;
}
void push(int q1[],int q2[],int n,int *f1,int *f2,int *r1,int  *r2)
{
    if(*r1==n-1) printf("Stack is full\n");
    else
    {
        int a;
        printf("Enter element: ");
        scanf("%d",&a);
        enqueue(q2,f2,r2,a);
        while(*f1!=-1)
        {
            enqueue(q2,f2,r2,dequeue(q1,f1,r1));
        }
        for (int i = 0; i <=*r2; i++)
        {
            q1[i]=q2[i];
        }
        int t1=*f1;
        *f1=*f2;
        *f2=t1;

        int t2=*r1;
        *r1=*r2;
        *r2=t2;
    }
}
void pop(int q1[],int *f1,int *r1)
{
    if(*f1==-1) printf("Stack is empty\n");
    else
    {
        printf("Deleted element is: %d\n",dequeue(q1,f1,r1));
    }
}
void display(int q1[],int f1,int r1)
{
    if(f1==-1) printf("Stack is empty\n");
    else
    {
    for (int i = r1; i>=f1; i--)
    {
        printf("%d ",q1[i]);
    }
    }
    printf("\n");
}
void main()
{
    int n,a;
    printf("Enter size of an array: ");
    scanf("%d",&n);
    int q1[n],q2[n],f1=-1,f2=-1,r1=-1,r2=-1;
    do
    {
        printf("Press [1] to push\n");
        printf("Press [2] to pop\n");
        printf("Press [3] to display\n");
        printf("Press [0] to exit\n");
        scanf("%d",&a);

        switch(a)
        {
            case 0:
                printf("Exit..\n");
                break;
            case 1:
                push(q1,q2,n,&f1,&f2,&r1,&r2);
                break;
            case 2:
                pop(q1,&f1,&r1);
                break;
            case 3:
                display(q1,f1,r1);
                break;
            default:
                printf("Invalid input,try again..\n");
                break;
        }
    }while(a!=0);
}