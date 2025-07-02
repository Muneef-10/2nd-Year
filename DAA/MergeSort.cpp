#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int> &v, int l,int mid,int r)
{
    int n1=mid-l+1,n2=r-mid;
    int k=l;
    vector<int> L(n1),R(n2);
    for (int i = 0; i < n1; i++)
        L[i]=v[k++];
    for (int j = 0; j < n2; j++)
        R[j]=v[k++];
    int i=0,j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<R[j])
            v[k++]=L[i++];
        else
            v[k++]=R[j++];
    }
    while(i<n1)
        v[k++]=L[i++];    
    while(j<n2)
        v[k++]=R[j++];    
}
void mergeSort(vector<int> &v,int l,int r)
{
    if(l<r)
    {
        int mid= l+(r-l)/2;
        mergeSort(v,l,mid);
        mergeSort(v,mid+1,r);
        Merge(v,l,mid,r);
    }
}
int main()
{
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    vector<int> v(size);
    cout<<"Enter elements: "<<endl;
    for (int i = 0; i < size; i++)
        cin>>v[i];
    
    mergeSort(v,0,size-1);
    cout<<"Sorted array:"<<endl;
    for (int i = 0; i < size; i++)
        cout<<v[i]<<" ";
    return 0;
}