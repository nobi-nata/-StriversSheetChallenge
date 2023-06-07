#include <bits/stdc++.h>

void bfs(int row, int col, vector<vector<int>> &vis, int **arr, int n, int m)
{
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int nrow = row + i;
                int ncol = col + j;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && arr[nrow][ncol] == 1 && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}

int getTotalIslands(int **arr, int n, int m)
{
    int cnt = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (!vis[row][col] && arr[row][col] == 1)
            {
                cnt++;
                bfs(row, col, vis, arr, n, m);
            }
        }
    }
    return cnt;
}
