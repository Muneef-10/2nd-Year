/*c++ STL divided into 4 parts:
Algorithm 
Containers
Functions
Iterators  */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    pair<int,int> p={1,2};
    pair<int,int> p3={14,25};
    cout<<p.first<<" "<<p.second<<endl;

    // p.swap(p3);
    swap(p,p3);
    cout<<"p1: "<<p.first<<" "<<p.second<<endl;
    cout<<"p2: "<<p3.first<<" "<<p3.second<<endl;
    
    pair<int,pair<int,int>> p2;
    p2={5,{6,7}};
    cout<<p2.first<<" "<<p2.second.second<<" "<<p2.second.first<<endl;

    pair<int,int> arr[]={{1,2},{3,4},{5,6},{7,8}};
    cout<<arr[2].first<<endl;
    for (int i = 0; i < 4; i++)
    {
        cout<<arr[i].first<<" "<<arr[i].second<<" ";
    }
    

    return 0;
}