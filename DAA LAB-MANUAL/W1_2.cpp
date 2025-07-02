// Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether given key element is present in the array or not. Also, find total number of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input)

#include<bits/stdc++.h>
using namespace std;
void BinarySearch(vector<int> v,int low,int high,int key,int comp)
{
    comp++;
    while(high>=low)
    {
        int mid=low+(high-low)/2;
        if(key<v[mid])
            return BinarySearch(v,low,mid-1,key,comp);        
        else if(key>v[mid])
            return BinarySearch(v,mid+1,high,key,comp);
        else
        {
            cout<<"Key is present in array, Number of comparisions are: "<<comp;
            return;
        }
    }
    cout<<"Key is Not present in array, Number of comparisions are: "<<comp;
    return;
}
int main()
{
    int size;
    cout<<"Enter size of array: "<<endl;
    cin>>size;
    vector<int> v(size);
    cout<<"Enter element in sorted order: "<<endl;
    for (int i = 0; i < size; i++)
        cin>>v[i];
    int high=size-1,key;
    cout<<"Enter key element: ";
    cin>>key;
    BinarySearch(v,0,high,key,0);

    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;
}