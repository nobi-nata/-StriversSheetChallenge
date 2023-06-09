#include <bits/stdc++.h>

bool isSafe(int node, int color[], vector<vector<int>> &mat, int n, int col)
{
    for (int i = 0; i < n; i++)
    {
        if (i != node && mat[node][i] == 1 && color[i] == col)
        {
            return false;
        }
    }
    return true;
}

bool solve(int node, int color[], vector<vector<int>> &mat, int m, int n)
{
    if (node == n)
    {
        return true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, color, mat, n, i))
        {
            color[node] = i;
            if (solve(node + 1, color, mat, m, n))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m)
{
    int n = mat.size();
    int color[n] = {0};
    if (solve(0, color, mat, m, n))
        return "YES";
    return "NO";
}