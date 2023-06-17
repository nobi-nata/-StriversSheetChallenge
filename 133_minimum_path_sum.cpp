//recursion
#include <bits/stdc++.h>

int f(int i, int j, vector<vector<int>> &grid)
{
    if (i == 0 && j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return INT_MAX;

    return grid[i][j] + min(f(i - 1, j, grid), f(i, j - 1, grid));
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    return f(n - 1, m - 1, grid);
}

//memoization
#include <bits/stdc++.h>

int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return INT_MAX;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = grid[i][j] + min(f(i - 1, j, grid, dp), f(i, j - 1, grid, dp));
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, grid, dp);
}

//tabulation
#include <bits/stdc++.h>

int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return INT_MAX;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = grid[i][j] + min(f(i - 1, j, grid, dp), f(i, j - 1, grid, dp));
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else
            {
                int up = grid[i][j];
                if (i > 0)
                    up += dp[i - 1][j];
                else
                    up += 1e9;

                int left = grid[i][j];
                if (j > 0)
                    left += dp[i][j - 1];
                else
                    left += 1e9;
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n - 1][m - 1];
}

//space-optimization
#include <bits/stdc++.h>

int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return INT_MAX;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = grid[i][j] + min(f(i - 1, j, grid, dp), f(i, j - 1, grid, dp));
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m, 0), cur(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                cur[j] = grid[i][j];
            else
            {
                int up = grid[i][j];
                if (i > 0)
                    up += prev[j];
                else
                    up += 1e9;

                int left = grid[i][j];
                if (j > 0)
                    left += cur[j - 1];
                else
                    left += 1e9;
                cur[j] = min(up, left);
            }
        }
        prev = cur;
    }
    return prev[m - 1];
}