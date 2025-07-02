//Bubble
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
        for (int j = 0; j < n-1; j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }

        }
        
    }
    cout<<"Sorted array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }    
}