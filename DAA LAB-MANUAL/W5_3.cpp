// You have been given two sorted integer arrays of size m and n. Design an algorithm and implement it using a program to find list of elements which are common to both. (Time Complexity = O(m+n))
#include <bits/stdc++.h>
using namespace std;

vector<int> findCommonElements(vector<int>& v1, vector<int>& v2) {
    int i = 0, j = 0;
    vector<int> common;

    while (i < v1.size() && j < v2.size()) {
        if (v1[i] == v2[j]) { 
            common.push_back(v1[i]); 
            i++; 
            j++; 
        }
        else if (v1[i] < v2[j]) i++;  
        else j++;  
    }    
    return common;
}

int main()
{
    int size1,size2;
    cout<<"Enter size of array 1: ";
    cin>>size1;

    vector<int> v1(size1);
    cout<<"Enter elements of array 1 in sorted order:"<<endl;
    for (int i = 0; i < size1; i++)
    cin>>v1[i];

    cout<<"Enter size of array 2: ";
    cin>>size2;

    vector<int> v2(size2);
    cout<<"Enter elements of array 2 in sorted order:"<<endl;
    for (int i = 0; i < size2; i++)
        cin>>v2[i];

    vector<int> result = findCommonElements(v1, v2);
    
    if (!result.empty()) 
    {
        cout << "Common Elements: ";
        for (int num : result)
            cout << num << " ";
    } 
    else 
        cout << "No common elements found";

    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;
    return 0;
}