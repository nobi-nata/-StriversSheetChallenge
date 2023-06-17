#include <bits/stdc++.h>

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    sort(arr.begin(), arr.end());
    int kthSmall = arr[k - 1];
    int kthLarge = arr[n - k];
    return {kthSmall, kthLarge};
}