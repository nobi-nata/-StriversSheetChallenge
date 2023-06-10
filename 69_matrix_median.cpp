#include <bits/stdc++.h>

int getMedian(vector<vector<int>> &arr)
{
    int row = arr.size();
    int col = arr[0].size();
    int median[row * col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            median[col * i + j] = arr[i][j];
        }
    }
    sort(median, median + row * col);
    return median[(row * col) / 2];
}