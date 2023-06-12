#include <bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<pair<int, int>, int>> prim;
    vector<pair<int, int>> adj[n + 1];
    for (auto i : g)
    {
        adj[i.first.first].push_back({i.first.second, i.second});
        adj[i.first.second].push_back({i.first.first, i.second});
    }
    vector<int> vis(n + 1, 0);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    pq.push({0, {1, -1}});

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second.first;
        int parent = it.second.second;
        int wt = it.first;
        if (vis[node] == 1)
            continue;
        vis[node] = 1;
        if (parent != -1)
        {
            prim.push_back({{parent, node}, wt});
        }
        for (auto i : adj[node])
        {
            int nw = i.second;
            int an = i.first;
            if (!vis[an])
            {
                pq.push({nw, {an, node}});
            }
        }
    }
    return prim;
}
