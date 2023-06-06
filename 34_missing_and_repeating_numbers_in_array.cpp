#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    int h[n + 1] = {0};
    for (auto i : arr)
    {
        h[i]++;
    }
    int rep, mis;
    for (int i = 1; i <= n; i++)
    {
        if (h[i] == 2)
            rep = i;
        if (h[i] == 0)
            mis = i;
    }
    return {mis, rep};
}
