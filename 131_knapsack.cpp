//RECURSION
#include <bits/stdc++.h>

int f(int ind, int w, vector<int> &val, vector<int> &wt)
{
    if (ind == 0)
    {
        if (wt[0] <= w)
            return val[0];
        return 0;
    }

    int nottake = f(ind - 1, w, val, wt);
    int take = INT_MIN;
    if (wt[ind] <= w)
        take = val[ind] + f(ind - 1, w - wt[ind], val, wt);
    return max(take, nottake);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    return f(n - 1, w, values, weights);
}

//MEMOIZATION
#include <bits/stdc++.h>

int f(int ind, int w, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (wt[0] <= w)
            return val[0];
        return 0;
    }
    if (dp[ind][w] != -1)
        return dp[ind][w];

    int nottake = f(ind - 1, w, val, wt, dp);
    int take = INT_MIN;
    if (wt[ind] <= w)
        take = val[ind] + f(ind - 1, w - wt[ind], val, wt, dp);
    return dp[ind][w] = max(take, nottake);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return f(n - 1, w, values, weights, dp);
}

//TABULATION
#include <bits/stdc++.h>

int maxProfit(vector<int> &val, vector<int> &wt, int n, int w)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for (int W = wt[0]; W <= w; W++)
        dp[0][W] = val[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int nottake = dp[i - 1][j];
            int take = INT_MIN;
            if (wt[i] <= j)
                take = val[i] + dp[i - 1][j - wt[i]];
            dp[i][j] = max(take, nottake);
        }
    }
    return dp[n - 1][w];
}

//SPACE-OPTIMIZE
#include <bits/stdc++.h>

int maxProfit(vector<int> &val, vector<int> &wt, int n, int w)
{
    vector<int> prev(w + 1, 0), cur(w + 1, 0);
    for (int W = wt[0]; W <= w; W++)
        prev[W] = val[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int nottake = prev[j];
            int take = INT_MIN;
            if (wt[i] <= j)
                take = val[i] + prev[j - wt[i]];
            cur[j] = max(take, nottake);
        }
        prev = cur;
    }
    return prev[w];
}

//MORE-SPACE-OPTIMISED
#include <bits/stdc++.h>

int maxProfit(vector<int> &val, vector<int> &wt, int n, int w)
{
    vector<int> prev(w + 1, 0);
    for (int W = wt[0]; W <= w; W++)
        prev[W] = val[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = w; j >= 0; j--)
        {
            int nottake = prev[j];
            int take = INT_MIN;
            if (wt[i] <= j)
                take = val[i] + prev[j - wt[i]];
            prev[j] = max(take, nottake);
        }
    }
    return prev[w];
}