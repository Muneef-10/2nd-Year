// #include <bits/stdc++.h>
// using namespace std;

// int countRecur(vector<int>& coins, int n, int sum) {
  
//     if (sum == 0) return 1;

//     if (sum < 0 || n == 0) return 0;

//     return countRecur(coins, n, sum - coins[n - 1]) + 
//             countRecur(coins, n - 1, sum);
// }

// int count(vector<int> &coins, int sum) {
//     return countRecur(coins, coins.size(), sum);
// }

// int main() {
//     vector<int> coins = {1, 2, 3};
//     int sum = 5;
//     cout << count(coins, sum);
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int countRecur(vector<int>& coins, int n, int sum, vector<vector<int>>& dp) {
    if (sum == 0) return 1;
    if (sum < 0 || n == 0) return 0;

    if (dp[n][sum] != -1) return dp[n][sum];

    dp[n][sum] = countRecur(coins, n, sum - coins[n - 1], dp) +
                 countRecur(coins, n - 1, sum, dp);

    return dp[n][sum];
}

int count(vector<int> &coins, int sum) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    return countRecur(coins, n, sum, dp);
}

int main() {
    vector<int> coins = {2,6,5, 3};
    int sum = 10;
    cout << count(coins, sum);
    return 0;
}
