#include <bits/stdc++.h>

bool dfs(int s, int c, vector<int> adj[], int color[])
{
    color[s] = c;
    for (auto i : adj[s])
    {
        if (color[i] == -1)
        {
            if (!dfs(i, !c, adj, color))
                return false;
        }
        else if (color[i] == c)
            return false;
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges)
{
    int n = edges.size();
    vector<int> adj[n] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int color[n];
    for (int i = 0; i < n; i++)
        color[i] = -1;
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (dfs(i, 0, adj, color) == false)
                return false;
        }
    }
    return true;
}