#include<bits/stdc++.h>
using namespace std;
void TOH(int n,char s,char a,char d,int &x)
{
    if(n==0) return;
    TOH(n-1,s,d,a,x);
    x++;
    cout<<x<<".) Disk move from "<<s<<" - "<<d<<endl;
    TOH(n-1,a,s,d,x);
}
int main()
{
    int n;
    cin>>n;
    int x=0;
    TOH(n,'A','B','C', x);
    return 0;
}