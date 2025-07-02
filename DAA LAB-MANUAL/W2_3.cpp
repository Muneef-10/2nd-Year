// Given an array of nonnegative integers, design an algorithm and a program to count the number of pairs of integers such that their difference is equal to a given key, K.

#include<bits/stdc++.h>
using namespace std;
void PairDifference(vector<int> v,int key)
{
    int size=v.size(),count=0;
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(abs(v[i]-v[j])==key)
                count++;
        }
    }
    cout<<"Number of pairs of integers are: "<<count;
}
int main()
{
    int size;
    cout<<"Enter size of array: "<<endl;
    cin>>size;
    vector<int> v(size);
    cout<<"Enter non-negative element only: "<<endl;
    for (int i = 0; i < size; i++)
        cin>>v[i];
    int key;
    cout<<"Enter key element: ";
    cin>>key;
    PairDifference(v,key);

    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;   
    return 0;
}