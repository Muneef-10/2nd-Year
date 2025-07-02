//Selection
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
    for (int i = 0; i < n-1; i++)
    {
        int min=i;
        for (int j = i+1; j < n; j++)
        {
            if(a[min]>a[j]) min=j;
        }
        if(min!=i)
        {
            int tmp=a[min];
            a[min]=a[i];
            a[i]=tmp;
        }
    }
    cout<<"Sorted array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
}