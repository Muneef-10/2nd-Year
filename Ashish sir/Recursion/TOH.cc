#include<iostream>
using namespace std;
void toh(int n,char from, char to,char aux)
{
    if(n==0) return;
    toh(n-1,from,aux,to);
    cout<<"Disk move "<<from<<" to "<<to<<endl;
    toh(n-1,aux,to,from);
}
int main()
{
    int n;
    cout<<"Enter number of disk: ";
    cin>>n;
    toh(n,'A','B','C');
    return 0;
}