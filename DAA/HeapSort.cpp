#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int> &v,int n,int i)
{
    int largest =i;
    int l=2*i,r=2*i+1;
    if(l<=n && v[l]>v[largest])
        largest = l;
    if(r<=n && v[r]>v[largest])
        largest = r;
    if(largest !=i)
    {
        swap(v[largest],v[i]);
        heapify(v,n,largest);
    }
}
void heapsort(vector<int> &v,int n)
{
    for(int i=n/2;i>=1;i--)
        heapify(v,n,i);
    for(int i=n;i>=1;i--)
    {
        swap(v[i],v[1]);
        heapify(v,i-1,1);
    }
}
int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;
    vector<int>v(n);
    for (int i = 1; i <=n; i++)
        cin>>v[i];

    heapsort(v,n);
    cout<<"Sorted array:"<<endl;
    for (int i = 1; i <=n; i++)
        cout<<v[i]<<" ";
    
    
    return 0;
}