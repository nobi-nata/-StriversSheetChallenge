#include <bits/stdc++.h>

void solve(int r, int c, vector<vector<int>> &maze, vector<int> &vis, vector<vector<int>> &ans, int n)
{
    if (r == n - 1 && c == n - 1)
    {
        ans.push_back(vis);
        return;
    }

    int dr[] = {1, 0, -1, 0};
    int dc[] = {0, -1, 0, 1};

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[n * nr + nc] && maze[nr][nc] == 1)
        {
            vis[n * nr + nc] = 1;
            solve(nr, nc, maze, vis, ans, n);
            vis[n * nr + nc] = 0;
        }
    }
}

vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{
    vector<int> vis(n * n, 0);
    vector<vector<int>> ans;
    vis[0] = 1;
    solve(0, 0, maze, vis, ans, n);
    return ans;
}