#include<bits/stdc++.h>
using namespace std;
void CountSort(vector<int> &arr,int n)
{

    int max = *max_element(arr.begin(),arr.end());
    vector<int> freq(max+1,0);
    for (int i = 0; i <n; i++)
    {
        freq[arr[i]]++;
    }
    for (int i = 1; i <=max; i++)
        freq[i]+=freq[i-1];
    
    vector<int> op(n);
    int i=n-1;
    while(i>=0)
    {
        op[--freq[arr[i]]]=arr[i];
        i--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i]=op[i];
    }        
}
int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    
    CountSort(arr,n);
    
    for (int i = 0; i <n; i++)
        cout<<arr[i]<<" ";
    return 0;
}