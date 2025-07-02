// Given an array of nonnegative integers, design a linear algorithm and implement it using a program to find whether given key element is present in the array or not. Also, find total number of comparisons for each input case. (Time Complexity = O(n), where n is the size of input)

#include<bits/stdc++.h>
using namespace std;
void check(vector<int> v,int size,int key)
{
    int comparision=0;
    for (int i = 0; i < size; i++)
    {
        comparision++;
        if(v[i]==key)
        {
            cout<<"Key is Present in array, Number of comparisions are: "<<comparision<<endl;
            return;
        }
    }
    cout<<"Key is Not Present in array, Number of comparisions are: "<<comparision<<endl;
    
}
int main()
{
    int size,key;
    cout<<"Enter size of array: ";
    cin>>size;
    vector<int> v(size);
    cout<<"Enter array elements: "<<endl;
    for (int i = 0; i < size; i++)
        cin>>v[i];
    cout<<"Enter key: ";
    cin>>key;
    check(v,size,key);
    
    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;

    return 0;
}