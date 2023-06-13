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


/// optimised solution
#include <bits/stdc++.h>

int findNo(vector<int> &a, int mid)
{
    int l = 0;
    int h = a.size() - 1;
    while (l <= h)
    {
        int m = (l + h) >> 1;
        if (a[m] <= mid)
            l = l + 1;
        else
            h = h - 1;
    }
    return l;
}

int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;
    int high = 0;
    for (int i = 0; i < n; i++)
    {
        high = max(high, matrix[i][m - 1]);
    }
    // int high = 1e5;

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += findNo(matrix[i], mid);
        }
        if (cnt <= (n * m) / 2)
            low = low + 1;
        else
            high = high - 1;
    }
    return low;
}