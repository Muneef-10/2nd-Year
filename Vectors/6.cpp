//Check of the given array is sorted(in ascending order) or not.

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int a=0;
    // for (int i = 0; i < n-1; i++)
    // {
    //     for (int j = i+1; j < n; j++)
    //     {
    //         if(v[j]<v[i])
    //         {
    //             a=1;
    //             break;
    //         }
    //     }
        
    // }
    // next method

    for (int i = 1; i < n; i++)
    {
        if(v[i]<v[i-1]) a=1;
    }
    

    if(a==0) cout<<"Yes";  //if(!a) cout<<"Yes";
    else cout<<"No";
    
    

    return 0;
}