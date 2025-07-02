#include<bits/stdc++.h>
using namespace std;
void BinarySearch(int a[],int n,int key)
{
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        int mid=(start+end)/2;//mid=start+(end-start)/2;
        if(key>a[mid])
            start=mid+1;
        else if(key<a[mid])
            end=mid-1;
        else
        {
            cout<<"Element is found at index "<<mid<<endl;
            return;
        }
    }
    cout<<"Element not found"<<endl;
}
int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int a[n];
    cout<<"Enter elements in sorted order: "<<endl;
    for (int i = 0; i < n; i++)
        cin>>a[i];
    int target;
    cout<<"Enter element to search: ";
    cin>>target;
    BinarySearch(a,n,target);
    return 0;
}