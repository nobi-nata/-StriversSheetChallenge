//recursion
#include <bits/stdc++.h>

long f(int ind, int T, int *deno)
{
    if (ind == 0)
    {
        return (T % deno[0] == 0);
    }

    long nottake = f(ind - 1, T, deno);
    long take = 0;
    if (deno[ind] <= T)
        take = f(ind, T - deno[ind], deno);
    return nottake + take;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    return f(n - 1, value, denominations);
}

//memoization
#include <bits/stdc++.h>

long f(int ind, int T, int *deno, vector<vector<long>> &dp)
{
    if (ind == 0)
    {
        return (T % deno[0] == 0);
    }
    if (dp[ind][T] != -1)
        return dp[ind][T];
    long nottake = f(ind - 1, T, deno, dp);
    long take = 0;
    if (deno[ind] <= T)
        take = f(ind, T - deno[ind], deno, dp);
    return dp[ind][T] = nottake + take;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return f(n - 1, value, denominations, dp);
}

//tabulation
#include <bits/stdc++.h>

long countWaysToMakeChange(int *deno, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));
    for (int T = 0; T <= value; T++)
    {
        dp[0][T] = (T % deno[0] == 0);
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= value; T++)
        {
            long nottake = dp[ind - 1][T];
            long take = 0;
            if (deno[ind] <= T)
                take = dp[ind][T - deno[ind]];
            dp[ind][T] = nottake + take;
        }
    }
    return dp[n - 1][value];
}

//space-optimization
#include <bits/stdc++.h>

long countWaysToMakeChange(int *deno, int n, int value)
{
    vector<long> prev(value + 1, 0), cur(value + 1, 0);
    for (int T = 0; T <= value; T++)
    {
        prev[T] = (T % deno[0] == 0);
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= value; T++)
        {
            long nottake = prev[T];
            long take = 0;
            if (deno[ind] <= T)
                take = cur[T - deno[ind]];
            cur[T] = nottake + take;
        }
        prev = cur;
    }
    return prev[value];
}