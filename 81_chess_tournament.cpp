#include <bits/stdc++.h>

bool isPossible(int limit, int k, vector<int> &arr)
{
    int coor = arr[0];
    int n = arr.size();
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - coor >= limit)
        {
            cnt++;
            coor = arr[i];
        }
        if (cnt == k)
            return true;
    }
    if (cnt < k)
        return false;
    return true;
}

int aggressiveCows(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int low = 1;
    int high = arr[n - 1] - arr[0];
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (isPossible(mid, k, arr))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}