#include <bits/stdc++.h>

// dfs calling
void dfs(unordered_map<int, list<int>> &adjlist, int node, vector<int> &c, unordered_map<int, bool> &visited)
{
    c.push_back(node);
    visited[node] = 1;
    // iterating through each component of adlist of a particular node .
    for (auto i : adjlist[node])
    {
        if (!visited[i])
        {
            dfs(adjlist, i, c, visited);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    // prepare the adjlist
    unordered_map<int, list<int>> adjlist;
    // preparing
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;
    // traveling to all the nodes
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            // if the graph is disconnected we will store diffrent component of it.
            vector<int> c;
            dfs(adjlist, i, c, visited);
            ans.push_back(c);
        }
    }
    return ans;
}