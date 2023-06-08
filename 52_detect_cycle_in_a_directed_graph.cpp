#include <bits/stdc++.h>

bool dfs(int s, vector<int> adj[], int vis[], int pvis[])
{
    vis[s] = 1;
    pvis[s] = 1;
    for (auto i : adj[s])
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, pvis))
                return true;
        }
        else if (pvis[i])
            return true;
    }
    pvis[s] = 0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    int m = edges.size();
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }
    int vis[n + 1] = {0};
    int pvis[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, pvis))
            {
                return true;
            }
        }
    }
    return false;
}