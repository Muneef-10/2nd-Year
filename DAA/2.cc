#include<bits/stdc++.h>
using namespace std;

// int missingNumber(vector<int>& nums) 
//     {
//         int n=nums.size(),ans;
//         vector<int> v(n,0);
//         for(int i=1;i<=n;i++)
//         {
//             if(nums[i]>=0 &&)
//                 v[nums[i]]=1;
//         }
//         for(int i=1;i<=n;i++)
//         {
//             if(v[i]==0)
//                 return i;
//         }
//     }
int missingNumber(vector<int>& nums) 
    {
        int n=nums.size();
        int expected=(n*(n+1))/2;
        int actual=0;
        for(int i=0;i<n;i++)
        {
            actual=actual+nums[i];
        }
        return expected-actual;
    }
int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter elements : "<<endl;
    for (int i = 0; i < n; i++)
        cin>>nums[i];
    cout<<missingNumber(nums);
    return 0;
}