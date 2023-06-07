#include <bits/stdc++.h>

bool bfs(vector<vector<int>> &adj, int vis[], int src)
{
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push({it, node});
            }
            else if (it != parent)
            {
                return true;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    vector<vector<int>> adj(n + 1);
    for (auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    int vis[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (bfs(adj, vis, i))
                return "Yes";
        }
    }
    return "No";
}
