#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int left, int mid, int right, int &comparisons) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left, invCount = 0;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            invCount += (n1 - i); 
        }
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    return invCount;
}

void mergeSort(vector<int> &arr, int left, int right, int &comp, int &inver) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid, comp, inver);
        mergeSort(arr, mid + 1, right, comp, inver);
        inver += merge(arr, left, mid, right, comp); 
    }
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter elements: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    int comp = 0;
    int inver = 0;

    mergeSort(arr, 0, size - 1, comp, inver);

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    
    cout << "\nNumber of comparisons = " << comp << endl;
    cout << "Number of inversions = " << inver << endl;

    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;
    return 0;
}
