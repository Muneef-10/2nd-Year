#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i)
{
    int parent =i;
    int left =2*i+1;
    int right =2*i+2;
    if(left<=n && arr[left]>arr[parent])
    {
        parent = left;
    }
    if(right<=n && arr[right]>arr[parent])
    {
        parent = right;
    }
    if(parent !=i)
    {
        swap(arr[i],arr[parent]);
        heapify(arr,n,parent);
    }
}
void heapsort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    for (int i = n; i >=1; i--)
    {
        swap(arr[i],arr[1]);
        heapify(arr,i-1,1);
    }
    
}
int main()
{
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: "<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    heapsort(arr,n);

    for (int i = 0; i <n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;    

    return 0;
}