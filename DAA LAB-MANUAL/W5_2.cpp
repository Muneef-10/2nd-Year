//Given an unsorted array of integers, design an algorithm and implement it using a program to find whether two elements exist such that their sum is equal to the given key element. (Time Complexity = O(n log n))

#include <bits/stdc++.h>
using namespace std;

bool hasPairWithSum(vector<int>& arr, int key) {
    sort(arr.begin(), arr.end()); // O(n log n) sorting

    int left = 0, right = arr.size() - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == key) {
            cout << "Pair found: (" << arr[left] << ", " << arr[right] << ")\n";
            return true;
        }
        else if (sum < key) {
            left++; 
        }
        else {
            right--; 
        }
    }
    
    return false;
}

int main() {
    // vector<int> arr = {10, 3, 5, 8, 2, 7, 4};
    // int key = 10;
    int size,key;
    cout<<"Enter size of array: ";
    cin>>size;
    vector<int> v(size);
    cout<<"Enter elements :"<<endl;
    for (int i = 0; i < size; i++)
        cin>>v[i];
    cout<<"enter key element: ";
    cin>>key;
    
    if (!hasPairWithSum(v, key)) {
        cout << "No pair found\n";
    }

    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;
    return 0;
}