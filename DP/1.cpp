/*// fibonacci    Memoisation
#include<bits/stdc++.h>
using namespace std;
int fib(int n)
{
    if(n<=1) return n;
    return fib(n-1)+fib(n-2);
}
int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<fib(n)<<endl;
    vector<int> ans;
    for (int i = 0; i <=n; i++)
    {
        ans.push_back(fib(i));
    }
    for (int i = 0; i <=n; i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}*/

// fibonacci  Tabulation
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    vector<int> dp(n);
    // dp[0]=0,dp[1]=1;
    // for (int i = 2; i <=n; i++)              here space is O(n)  now we optimize it too
    // {
    //     dp[i]=dp[i-1]+dp[i-2];
    // }
    // cout<<dp[n];

    int prev2=0, prev=1, curr=0;
    for (int i = 2; i <=n; i++)
    {
        curr=prev2+prev;
        prev2=prev;
        prev=curr;
    }
    cout<<prev;


    
    return 0;
}