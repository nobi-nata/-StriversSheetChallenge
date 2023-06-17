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


//tabulation
#include <bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int ind = n-1; ind >= 0; ind--){
        for(int prev = ind-1; prev >= -1; prev--){
            int nottake = dp[ind+1][prev+1];
            int take = INT_MIN;
            if(prev == -1 || arr[ind] > arr[prev]){
                take = 1 + dp[ind+1][ind+1];
            }
            dp[ind][prev+1] = max(take, nottake);
        }
    }
    return dp[0][0];
}


//space-optimization
#include <bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> prev(n + 1, 0), cur(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int nottake = prev[prev_ind + 1];
            int take = INT_MIN;
            if (prev_ind == -1 || arr[ind] > arr[prev_ind])
            {
                take = 1 + prev[ind + 1];
            }
            cur[prev_ind + 1] = max(take, nottake);
        }
        prev = cur;
    }
    return prev[0];
}

//more-space-optimised
#include <bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> prev(n + 1, 0), cur(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int nottake = prev[prev_ind + 1];
            int take = INT_MIN;
            if (prev_ind == -1 || arr[ind] > arr[prev_ind])
            {
                take = 1 + prev[ind + 1];
            }
            prev[prev_ind + 1] = max(take, nottake);
        }
        // prev = cur;
    }
    return prev[0];
}

//tabulation algorithm
#include <bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n, 1);
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] > arr[prev])
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

//print LIS
#include <bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n, 1), hash(n);
    int maxi = 0;
    int lastIndex = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] > arr[prev] && dp[i] < 1 + dp[prev])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int> temp(maxi);
    temp.push_back(arr[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(), temp.end());

    return maxi;
}

//using binary_search
#include <bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    int len = 1;
    temp.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            len++;
            temp.push_back(arr[i]);
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return len;
}


