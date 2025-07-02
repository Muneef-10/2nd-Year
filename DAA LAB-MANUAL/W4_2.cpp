#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high, int &comparisons, int &swaps)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) 
    {
        comparisons++;  
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }

    swap(arr[i+1], arr[high]);
    swaps++;
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high, int &comparisons, int &swaps)
{
    if (low < high) {
        int pivotIndex = partition(arr, low, high, comparisons, swaps);
        quickSort(arr, low, pivotIndex - 1, comparisons, swaps);
        quickSort(arr, pivotIndex + 1, high, comparisons, swaps);
    }
}

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter elements: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    int comparisons = 0, swaps = 0;

    quickSort(arr, 0, size - 1, comparisons, swaps);

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << "\nNumber of comparisons = " << comparisons << endl;
    cout << "Number of swaps = " << swaps << endl;

    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;
    return 0;
}