// Given an unsorted array of integers, design an algorithm and implement it using a program to find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))
#include <bits/stdc++.h>
using namespace std;

int findKthSmallest(vector<int>& arr, int k) {
    int minElement = *min_element(arr.begin(), arr.end());
    int maxElement = *max_element(arr.begin(), arr.end());
    
    int range = maxElement - minElement + 1;
    vector<int> count(range, 0);

    for (int num : arr) {
        count[num - minElement]++;
    }

    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            index++;
            if (index == k) {
                return i + minElement;
            }
            count[i]--;
        }
    }
    return -1;
}

int main() 
{
    int size,key;
    cout<<"Enter size of array: ";
    cin>>size;
    vector<int> v(size);
    cout<<"Enter elements :"<<endl;
    for (int i = 0; i < size; i++)
        cin>>v[i];
    cout<<"enter key element: ";
    cin>>key;
    cout << "The " << key << "rd smallest element is: " << findKthSmallest(v, key) << endl;
    
    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;
    return 0;
}