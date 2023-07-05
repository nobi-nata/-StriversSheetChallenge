#include <bits/stdc++.h>

void solve(vector<vector<int>> &mat, int i, int j, int n, int m)
{

    if (m <= 1 || n <= 1)
        return;

    int prev = mat[i][j];

    // first row
    for (int k = j; k < m + j; k++)
        swap(mat[i][k], prev);

    // right col
    for (int k = i + 1; k < n + i; k++)
        swap(mat[k][m - 1 + j], prev);

    // last row
    for (int k = m - 2 + j; k >= 0 + j; k--)
        swap(mat[n - 1 + i][k], prev);

    // first col
    for (int k = n - 2 + i; k >= 0 + i; k--)
        swap(mat[k][j], prev);

    solve(mat, i + 1, j + 1, n - 2, m - 2);
}

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    solve(mat, 0, 0, n, m);
}