#include<stdio.h>
void main()
{
    int size;
    printf("Enter size of array: ");
    scanf("%d",&size);
    int a[size];
    printf("Enter element: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < size; i++)
    {
        if(a[i]==-1) continue;
        printf("%d ",a[i]);
        printf("%d ",a[2*i+1]);
        printf("%d ",a[2*i+2]);
    }
    
}