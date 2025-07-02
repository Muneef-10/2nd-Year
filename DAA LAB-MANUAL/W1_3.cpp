/* Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether a given key element is present in the sorted array or 
not. For an array arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k] and so on. Once the interval (arr[2k] <key < arr[ 2k+1] ) is found, perform a linear search 
operation from the index 2k to find the element key. (Complexity < O(n), where n is the number of elements need to be scanned for searching): 
Jump Search*/

#include<bits/stdc++.h>
using namespace std;
void JumpSearch(vector<int> v,int size,int key)
{
    int m=2;
    int low=0,high=m,comp=0;
    while(high<size &&key>v[high])
    {
        comp++;
        low=high;
        high=high+m;
    }
    if(high>size-1) high=size-1;
    for (int i = low; i <=high; i++)
    {
        comp++;
        if(v[i]==key)
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
    int size,key;
    cout<<"Enter size of array: ";
    cin>>size;
    vector<int> v(size);
    cout<<"Enter elements in sorted order:"<<endl;
    for (int i = 0; i < size; i++)
        cin>>v[i];
    cout<<"enter key element: ";
    cin>>key;
    JumpSearch(v,size,key);
    
    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;
    return 0;
}