#include <bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    int n = edges.size();
    vector<set<int>> adj(vertex);
    for (auto e : edges)
    {
        adj[e.first].insert(e.second);
        adj[e.second].insert(e.first);
    }
    int vis[vertex] = {0};
    vector<int> bfs;
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it : adj[node])
        {

            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
        if (q.empty())
        {
            for (int i = 0; i < vertex; i++)
            {
                if (vis[i] == 0)
                {
                    q.push(i);
                    vis[i] = 1;
                    break;
                }
            }
        }
    }
    return bfs;
}