// Given a sorted array of positive integers containing few duplicate elements, design an algorithm and implement it using a program to find whether the given key element is present in the array or not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))
#include<bits/stdc++.h>
using namespace std;
int FirstOccurrence(vector<int> v,int key)
{
    int first=-1,low=0,high=v.size()-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(key<v[mid])
            high=mid-1;       
        else if(key>v[mid])
            low=mid+1;
        else
        {
            first=mid;
            high=mid-1;
        }
    }
    return first;
}

int LastOccurrence(vector<int> v,int key)
{
    int last=-1,low=0,high=v.size()-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(key<v[mid])
            high=mid-1;       
        else if(key>v[mid])
            low=mid+1;
        else
        {
            last=mid;
            low=mid+1;
        }
    }
    return last;
}

void DuplicatePresent(vector<int> v,int key)
{
    int first=FirstOccurrence(v,key);
    if(first==-1)
    {
        cout<<"Key is Not present in array"<<endl;
        return;
    }
    int last=LastOccurrence(v,key);
    cout<<"Key is present in array in "<<last -first +1<<" times"<<endl;
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
    int key;
    cout<<"Enter key element: ";
    cin>>key;
    DuplicatePresent(v,key);
    
    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;
}