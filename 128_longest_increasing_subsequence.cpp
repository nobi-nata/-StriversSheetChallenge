//MEMOIZATION
#include <bits/stdc++.h>

int f(int ind, int prev, int arr[], int n, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];
    int len = 0 + f(ind + 1, prev, arr, n, dp);
    if (prev == -1 || arr[ind] > arr[prev])
    {
        len = max(len, 1 + f(ind + 1, ind, arr, n, dp));
    }
    return dp[ind][prev + 1] = len;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0, -1, arr, n, dp);
}
