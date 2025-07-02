//Insertion
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    int a[n];
    cout<<"Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    for (int i = 1; i < n; i++)
    {
        int j=i-1,tmp=a[i];
        while(j>=0 && a[j]>tmp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=tmp;
    }
    
    cout<<"Sorted array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
    
}