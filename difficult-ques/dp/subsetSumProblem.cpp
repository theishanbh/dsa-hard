#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int k)
    {
        int n = arr.size();
        // we are basically storing two states
        // whether at index i, we can make the target sum of k
        vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
        // for any i, we can always make 0 by not taking any element, so it will always return true (1)
        for (int i = 0; i < n; i += 1)
            dp[i][0] = 1;
        // if the array has one element, then the only way
        // to make the target is by taking the element itself
        if (arr[0] <= k)
            dp[0][arr[0]] = true;

        // since i = 0 is already done, we start from i = 1
        for (int i = 1; i < n; i += 1)
        {
            // we start from 1 because we have already done 0
            for (int target = 1; target <= k; target += 1)
            {
                bool take = false;
                // if the current element is less than or equal to the target
                // then only we can take it
                if (arr[i] <= target)
                    take = dp[i - 1][target - arr[i]];
                // if we dont take the current element
                // then we can check if the target can be made by the previous elements
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