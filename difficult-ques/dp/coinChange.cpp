
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int i = 0; i <= amount; i += 1)
        {
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
                dp[0][i] = 1e9;
        }

        for (int i = 1; i < n; i += 1)
        {
            for (int target = 0; target <= amount; target += 1)
            {
                int take = 1e9;
                if (coins[i] <= amount)
                {
                    take = 1 + dp[i][target - coins[i]];
                }
                int notTake = dp[i - 1][target];
                dp[i][target] = min(take, notTake);
            }
        }
        int x = dp[n - 1][amount];
        if (x >= 1e9)
            return -1;
        else
            return x;
    }
};