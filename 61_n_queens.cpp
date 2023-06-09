#include <bits/stdc++.h>

bool S(int row, int col, vector<int> board, int n)
{
    // check upper element
    int duprow = row;
    int dupcol = col;

    while (row >= 0 && col >= 0)
    {
        if (board[n * row + col] == 1)
            return false;
        row--;
        col--;
    }

    col = dupcol;
    row = duprow;
    while (col >= 0)
    {
        if (board[n * row + col] == 1)
            return false;
        col--;
    }

    row = duprow;
    col = dupcol;
    while (row < n && col >= 0)
    {
        if (board[n * row + col] == 1)
            return false;
        row++;
        col--;
    }
    return true;
}

void nq(int col, vector<int> &board, vector<vector<int>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (S(row, col, board, n))
        {
            board[n * row + col] = 1;
            nq(col + 1, board, ans, n);
            board[n * row + col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> ans;
    vector<int> board(n * n, 0);
    nq(0, board, ans, n);

    return ans;
}