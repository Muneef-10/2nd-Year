//Given a sorted array of positive integers, design an algorithm and implement it using a program to find three indices i, j, k such that arr[i] + arr[j] = arr[k].

#include<bits/stdc++.h>
using namespace std;
void TripleSum(vector<int>v,int size)
{
    int tmp=0;
    for(int k=size-1;k>=2;k--)
    {
        int i=0,j=k-1;
        while(i<j)
        {
            if(v[i]+v[j]==v[k])
            {
                tmp=1;
                cout<<"Elements position are ("<<i+1<<" ,"<<j+1<<" ,"<<k+1<<")"<<endl;
            }
            if(v[i]+v[j]>v[k])
                j--;
            else
                i++;
        }
    }
    if(tmp==0)
        cout<<"Indices Not found"<<endl;
    return;
}
int main()
{
    int size;
    cout<<"Enter size of array: "<<endl;
    cin>>size;
    vector<int> v(size);
    cout<<"Enter only positive element in sorted order: "<<endl;
    for (int i = 0; i < size; i++)
        cin>>v[i];
    TripleSum(v,size);

    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;
    return 0;
}