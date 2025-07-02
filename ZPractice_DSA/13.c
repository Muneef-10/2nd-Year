//TOH

#include<stdio.h>
void toh(int n, char from, char to,char aux)
{
    if(n==0) return;
    toh(n-1,from,aux,to);
    printf("Disk movement from %c to %c\n",from,to);
    toh(n-1,aux,to,from);
}
void main()
{
    int n=4;
    toh(n,'A','B','C');
}