#include<bits/stdc++.h>
using namespace std;
void reverse_string(int s,char a[],int e)
{
    if(s>=e) return ;
    char tmp=a[s];
    a[s]=a[e];
    a[e]=tmp;
    reverse_string(s+1,a,e-1);
}
int main()
{
    char a[50];
    cout<<"Enter a string: ";
    scanf("%[^\n]s",&a);
    int l=strlen(a);
    reverse_string(0,a,l-1);
    cout<<"Reversed string: "<<a;
    return 0;
}