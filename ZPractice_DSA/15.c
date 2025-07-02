#include<stdio.h>
#include<stdlib.h>
void allocate(int n,int m,int **ptr1,int **ptr2)
{
    *ptr1=(int*)malloc(sizeof(int)*n);
    *ptr1=(int*)malloc(sizeof(int)*m);
    for (int i = 0; i < n; i++)
    {
        (*ptr1)[i]=i+2;
    }
    for (int i = 0; i < m; i++)
    {
        (*ptr2)[i]=i+10;
    }
    
}
void main()
{
    int n,m,*ptr1,*ptr2;
    scanf("%d%d",&n,&m);
    allocate(n,m,&ptr1,&ptr2);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",ptr1[i]);
    }
    printf("\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d ",ptr2[i]);
    }

    free(ptr1);
    free(ptr2);
    
}