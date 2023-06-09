#include <bits/stdc++.h>

void dfs(int node, int vis[], vector<int> adj[], stack<int> &st)
{
    vis[node] = 1;
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    vector<int> adj[v] = {};
    int vis[v] = {0};
    stack<int> st;
    for (int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfs(i, vis, adj, st);
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}