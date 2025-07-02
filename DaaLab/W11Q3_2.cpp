#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int>& v, int sum) {
    int n = v.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (v[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - v[i - 1]];
            }
        }
    }
    
    return dp[n][sum];
}

int main() {
    int n, sum = 0;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) 
    {
        cin >> v[i];
        sum += v[i];
    }
    if (sum % 2 != 0) 
    {
        cout << "No";
        return 0;
    }

    if (subsetSum(v, sum / 2))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
