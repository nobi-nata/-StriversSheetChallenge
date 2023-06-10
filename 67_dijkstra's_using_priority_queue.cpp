#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int V, int e, int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<vector<int>> adj[V];
    for (int i = 0; i < e; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> dist(V, INT_MAX);

    // Source initialised with dist=0.
    dist[s] = 0;
    pq.push({0, s});

    // Now, pop the minimum distance node first from the min-heap
    // and traverse for all its adjacent nodes.
    while (!pq.empty())
    {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // Check for all adjacent nodes of the popped out
        // element whether the prev dist is larger than current or not.
        for (auto it : adj[node])
        {
            int v = it[0];
            int w = it[1];
            if (d + w < dist[v])
            {
                dist[v] = d + w;

                // If current distance is smaller,
                // push it into the queue.
                pq.push({d + w, v});
            }
        }
    }
    // Return the list containing shortest distances
    // from source to all the nodes.
    return dist;
}
