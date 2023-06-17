//recursion
#include <bits/stdc++.h>

bool f(int ind, int target, vector<int> &arr)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return (arr[0] == target);

    bool nottake = f(ind - 1, target, arr);
    if (nottake)
        return true;
    bool take = false;
    if (arr[ind] <= target)
        return f(ind - 1, target - arr[ind], arr);
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return f(n - 1, k, arr);
}

//memoization
#include <bits/stdc++.h>

int f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;
    if (ind == 0)
        return (arr[0] == target);
    if (dp[ind][target] != -1)
        return dp[ind][target];
    int nottake = f(ind - 1, target, arr, dp);
    int take = 0;
    if (arr[ind] <= target)
        take = f(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = take | nottake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n - 1, k, arr, dp);
}

//tabulation
#include <bits/stdc++.h>

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool nottake = dp[ind - 1][target];
            bool take = false;
            if (arr[ind] <= target)
                take = dp[ind - 1][target - arr[ind]];
            dp[ind][target] = take | nottake;
        }
    }
    return dp[n - 1][k];
}

//space-optimization
#include <bits/stdc++.h>

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, false), cur(k + 1, false);
    prev[0] = cur[0] = true;
    prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool nottake = prev[target];
            bool take = false;
            if (arr[ind] <= target)
                take = prev[target - arr[ind]];
            cur[target] = take | nottake;
        }
        prev = cur;
    }
    return prev[k];
}

//more-space-optimised
#include <bits/stdc++.h>

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, false), cur(k + 1, false);
    prev[0] = true;
    prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = k; target >= 1; target--)
        {
            bool nottake = prev[target];
            bool take = false;
            if (arr[ind] <= target)
                take = prev[target - arr[ind]];
            prev[target] = take | nottake;
        }
    }
    return prev[k];
}