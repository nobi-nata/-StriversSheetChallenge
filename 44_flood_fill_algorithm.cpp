#include <bits/stdc++.h>
void dfs(vector<vector<int>> &ans, int iC, int r, int c, vector<vector<int>> &vis, int newColor, int dr[], int dc[])
{
    ans[r][c] = newColor;
    vis[r][c] = 1;
    int m = ans.size();
    int n = ans[0].size();
    for (int i = 0; i <= 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < m && nc >= 0 && nc < n && ans[nr][nc] == iC && !vis[nr][nc])
        {
            dfs(ans, iC, nr, nc, vis, newColor, dr, dc);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    vector<vector<int>> ans = image;
    int iC = ans[x][y];
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    int m = image.size();
    int n = image[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    dfs(ans, iC, x, y, vis, newColor, dr, dc);
    return ans;
}