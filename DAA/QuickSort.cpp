#include<bits/stdc++.h>
using namespace std;
int partition(vector<int> &v,int l,int r)
{
    int start=l,end=r,pivot=v[start];
    while(start<end)
    {
        while(v[start]<=pivot) start++;
        while(v[end]>pivot) end--;
        if(start<end)
            swap(v[start],v[end]);
        
    }
    swap(v[l],v[end]);
    return end;
}
void quickSort(vector<int> &v,int l,int r)
{
    if(l<r)
    {
        int part=partition(v,l,r);
        quickSort(v,l,part-1);
        quickSort(v,part+1,r);
    }
}
int main()
{
    int size;
    cout<<"Enter size: ";
    cin>>size;
    vector<int> v(size);
    cout<<"Enter array elements:"<<endl;
    for (int i = 0; i < size; i++)
        cin>>v[i];

    quickSort(v,0,size-1);
    cout<<"Sorted array is:"<<endl;
    for (int i = 0; i < size; i++)
        cout<<v[i]<<" ";
    return 0;
}