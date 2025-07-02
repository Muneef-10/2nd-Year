// Given an unsorted array of integers, design an algorithm and implement a program to sort this array using selection sort. Your program should also find number of comparisons and number of swaps required.

#include<bits/stdc++.h>
using namespace std;
void SelectionSort(vector<int> &v,int &swaps,int &comp)
{
    int size=v.size();
    for (int i = 0; i < size-1; i++)
    {
        int min=i;
        for (int j = i+1; j < size; j++)
        {
            comp++;
            if(v[j]<v[min]) min=j;
        }
        if(min!=i)
        {
            swap(v[i],v[min]);
            swaps++;
        }
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
    int swaps=0,comp=0;    
    SelectionSort(v,swaps,comp);
    for (int i = 0; i < size; i++)
        cout<<v[i]<<" ";
    cout<<"\nNumber of comparisons = "<<comp<<endl<<"Number of swaps = "<<swaps<<endl;

    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;
    return 0;
}