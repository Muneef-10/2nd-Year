#include<bits/stdc++.h>
using namespace std;
bool is_palindrome(int s,char a[], int e)
{
    if(s>=e) return true;
    if(a[s]!=a[e]) 
    {
        return false;
    }
    is_palindrome(s+1,a,e-1);
}
int main()
{
    char a[50];
    cout<<"Enter a string: ";
    scanf("%[^\n]s",&a);
    int l=strlen(a);
    if(is_palindrome(0,a,l-1)) cout<<"True";
    else cout<<"False";
    return 0;
}