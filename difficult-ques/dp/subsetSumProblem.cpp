#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int k)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
        // for any i, we can always make 0 by not taking any element, so it will always return true (1)
        for (int i = 0; i < n; i += 1)
            dp[i][0] = 1;
        // lets
        if (arr[0] <= k)
            dp[0][arr[0]] = true;

        for (int i = 1; i < n; i += 1)
        {
            for (int target = 1; target <= k; target += 1)
            {
                bool take = false;
                if (arr[i] <= target)
                    take = dp[i - 1][target - arr[i]];

                bool notTake = dp[i - 1][target];
                dp[i][target] = take || notTake;
            }
        }
        return dp[n - 1][k];
    }
};

// [1,2,3,0,0,0]
// l = 0
// [2,5,6]
// r = 2