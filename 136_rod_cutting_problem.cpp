//recursion
#include <bits/stdc++.h>

int f(int ind, int target, vector<int> &price)
{
    if (ind == 0)
    {
        return target * price[0];
    }

    int nottake = f(ind - 1, target, price);
    int take = INT_MIN;
    int rodlength = ind + 1;
    if (rodlength <= target)
        take = price[ind] + f(ind, target - rodlength, price);
    return max(take, nottake);
}

int cutRod(vector<int> &price, int n)
{
    return f(n - 1, n, price);
}

//memoization
#include <bits/stdc++.h>

int f(int ind, int target, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return target * price[0];
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];
    int nottake = f(ind - 1, target, price, dp);
    int take = INT_MIN;
    int rodlength = ind + 1;
    if (rodlength <= target)
        take = price[ind] + f(ind, target - rodlength, price, dp);
    return dp[ind][target] = max(take, nottake);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(n - 1, n, price, dp);
}


//tabulation
#include <bits/stdc++.h>

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[0][i] = i * price[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= n; target++)
        {
            int nottake = dp[ind - 1][target];
            int take = INT_MIN;
            int rodlength = ind + 1;
            if (rodlength <= target)
                take = price[ind] + dp[ind][target - rodlength];
            dp[ind][target] = max(take, nottake);
        }
    }
    return dp[n - 1][n];
}

//space-optimization
#include <bits/stdc++.h>

int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0), cur(n + 1, 0);
    for (int i = 0; i <= n; i++)
        prev[i] = i * price[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= n; target++)
        {
            int nottake = prev[target];
            int take = INT_MIN;
            int rodlength = ind + 1;
            if (rodlength <= target)
                take = price[ind] + cur[target - rodlength];
            cur[target] = max(take, nottake);
        }
        prev = cur;
    }
    return prev[n];
}


//more-space-optimised
#include <bits/stdc++.h>

int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0);
    for (int i = 0; i <= n; i++)
        prev[i] = i * price[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= n; target++)
        {
            int nottake = prev[target];
            int take = INT_MIN;
            int rodlength = ind + 1;
            if (rodlength <= target)
                take = price[ind] + prev[target - rodlength];
            prev[target] = max(take, nottake);
        }
    }
    return prev[n];
}
