#include <bits/stdc++.h>

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    int maxi = INT_MIN;
    int maxinext = 0;
    vector<pair<int, int>> ans;
    for (auto i : mpp)
    {
        ans.push_back({i.second, i.first});
    }
    sort(ans.begin(), ans.end(), greater<pair<int, int>>());
    vector<int> res;
    for (int i = 0; i < k; i++)
    {
        res.push_back(ans[i].second);
    }
    sort(res.begin(), res.end());
    return res;
}