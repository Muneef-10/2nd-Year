#include<iostream>
using namespace std;
void toh(int n,char from, char to,char aux,int *x)
{
    if(n==0) return;
    toh(n-1,from,aux,to,x);
    // cout<<"Disk move "<<from<<" to "<<to<<endl;
    (*x)++;
    toh(n-1,aux,to,from,x);
}
int main()
{
    int n,x=0;
    cout<<"Enter number of disk: ";
    cin>>n;
    toh(n,'A','B','C',&x);
    printf("%d ",x);
    return 0;
}