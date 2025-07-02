#include <bits/stdc++.h>
using namespace std;

void heapify(int *arr, int i, int n);
void buildheap(int *arr, int n) {
    for (int i = n/2 - 1; i >= 0; i--) { // Fixing the loop
        heapify(arr, i, n);
    }
}

void heapify(int *arr, int i, int n) {
    int c1 = 2 * i + 1, c2 = 2 * i + 2;
    int max = i;
    if (c1 < n && arr[c1] > arr[max])
        max = c1;
    if (c2 < n && arr[c2] > arr[max])
        max = c2;
    if (max != i) {
        swap(arr[max], arr[i]);
        heapify(arr, max, n);
    }
}

int main() {
    int a[10] = {62, 41, 85, 91, 24, 34, 14, 57, 76, 43};
    buildheap(a, 10);
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
