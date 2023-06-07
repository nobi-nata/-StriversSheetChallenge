#include <bits/stdc++.h>

int minTimeToRot(vector<vector<int>> &grid, int n, int m)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    int cF = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else if (grid[i][j] == 1)
            {
                cF++;
            }
        }
    }

    int cnt = 0;

    int mT = 0;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1)
            {
                vis[nr][nc] = 2;
                q.push({{nr, nc}, t + 1});
                cnt++;
                mT = max(mT, t + 1);
            }
        }
    }

    if (cnt == cF)
        return mT;
    return -1;
}