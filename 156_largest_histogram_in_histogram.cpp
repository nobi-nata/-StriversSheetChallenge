#include <bits/stdc++.h>
//BRUTE
int rm(int i, vector<int> &heights, int n)
{
    int e = heights[i];
    while (i < n - 1)
    {
        if (e <= heights[i + 1])
        {
            i++;
        }
        else
        {
            return i;
        }
    }
    return i;
}
int lm(int i, vector<int> &heights)
{
    int e = heights[i];
    while (i > 0)
    {
        if (e <= heights[i - 1])
        {
            i--;
        }
        else
        {
            return i;
        }
    }
    return i;
}

int largestRectangle(vector<int> &heights)
{
    int n = heights.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int leftmin = lm(i, heights);
        int rightmin = rm(i, heights, n);
        int ans = (rightmin - leftmin + 1) * heights[i];
        maxi = max(ans, maxi);
    }
    return maxi;
}