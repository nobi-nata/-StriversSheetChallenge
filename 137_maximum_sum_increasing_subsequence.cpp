#include <bits/stdc++.h>
int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
    vector<int> dp(n, 1), hash(n);
    int maxi = 0;
    int sum = arr[0];
    for (int i = 0; i < n; i++)
    {
        hash[i] = arr[i];
        int tempsum = 0;
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] > arr[prev] && dp[i] < 1 + dp[prev])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = max(hash[i], arr[i] + hash[prev]);
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            sum = hash[i];
        }
    }
    return sum;
}