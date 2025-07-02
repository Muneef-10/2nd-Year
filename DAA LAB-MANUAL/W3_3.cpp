// Given an unsorted array of positive integers, design an algorithm and implement it using a program to find whether there are any duplicate elements in the array or not. (use sorting) (Time Complexity = O(n log n))

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int low, int high) {
    int pivot = v[high]; 
    int i = low - 1; 

    for (int j = low; j < high; j++) {
        if (v[j] < pivot) { 
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return i + 1;
}

void quickSort(vector<int> &v, int low, int high) {
    if (low < high) {
        int pi = partition(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

bool hasDuplicate(vector<int> &v) {
    int size = v.size();

    quickSort(v, 0, size - 1);

    for (int i = 1; i < size; i++) {
        if (v[i] == v[i - 1]) {
            return true; 
        }
    }

    return false;
}

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    vector<int> v(size);
    cout << "Enter elements: ";
    for (int i = 0; i < size; i++)
        cin >> v[i];

    if (hasDuplicate(v))
        cout << "Duplicates present" << endl;
    else
        cout << "Duplicates Not present" << endl;

    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;

    return 0;
}