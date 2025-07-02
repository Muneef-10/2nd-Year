// Given an unsorted array of integers, design an algorithm and a program to sort the array using insertion sort. Your program should be able to find number of comparisons and shifts ( shifts-total number of times the array elements are shifted from their place) required for sorting the array.

#include<bits/stdc++.h>
using namespace std;
void InsertionSort(vector<int> &v,int &shift,int &comp)
{
    int size=v.size();
    comp=0,shift=0;
    for (int i = 1; i < size; i++)
    {
        int tmp=v[i],j=i-1;
        while(j>=0 && v[j]>tmp)
        {
            comp++;
            v[j+1]=v[j];
            shift++;
            j--;
        }
        v[j+1]=tmp;
        shift++;
    }
}
int main()
{
    int size;
    cout<<"Enter size of array: "<<endl;
    cin>>size;
    vector<int> v(size);
    cout<<"Enter element:"<<endl;
    for (int i = 0; i < size; i++)
        cin>>v[i];
    int shift=0,comp=0;    
    InsertionSort(v,shift,comp);
    for (int i = 0; i < size; i++)
        cout<<v[i]<<" ";
    cout<<"\nComparisons = "<<comp<<endl<<"shifts = "<<shift<<endl;

    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;
    return 0;
}