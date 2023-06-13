#include <bits/stdc++.h>

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, st);
        }
    }

    st.push(node);
}
void dfs3(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &ans)
{
    vis[node] = 1;
    ans.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs3(it, adj, vis, ans);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
    }
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }

    vector<vector<int>> adjT(V);
    for (int i = 0; i < V; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }

    int cnt = 0;
    vector<vector<int>> res;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            cnt++;
            vector<int> ans;
            dfs3(node, adjT, vis, ans);
            res.push_back(ans);
        }
    }
    return res;
}