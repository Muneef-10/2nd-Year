#include<iostream> 
using namespace std; 
 
int findMajorityVoting(int arr[], int n) { 
    int candidate = -1, count = 0; 
    for(int i = 0; i < n; i++) { 
        if(count == 0) { 
            candidate = arr[i]; 
            count = 1; 
        } else if(arr[i] == candidate) { 
            count++; 
        } else { 
            count--; 
        } 
    } 
    count = 0; 
    for(int i = 0; i < n; i++) { 
        if(arr[i] == candidate) count++; 
    } 
    if(count > n/2) return candidate; 
    return -1; 
} 
 
int main() { 
 
    int n; 
    cout << "Enter size of array:"; 
    cin >> n; 
    int arr[n]; 
    cout << "Enter elements of array:" << endl; 
    for(int i = 0; i < n; i++) { 
        cin >> arr[i]; 
    } 
 
    int majority = findMajorityVoting(arr, n); 
    if(majority != -1) 
        cout << "Majority element is: " << majority << endl; 
    else 
        cout << "No majority element exists." << endl; 
        
    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;
    return 0; 
}