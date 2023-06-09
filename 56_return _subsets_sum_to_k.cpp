#include <bits/stdc++.h>

void findSS(int ind, long long sum, vector<int> &num, vector<int> &ds, int k, vector<vector<int>> &ans)
{
    int n = num.size();
    if (ind == n)
    {
        if (sum == k)
        {
            ans.push_back(ds);
        }
        return;
    }

    ds.push_back(num[ind]);
    findSS(ind + 1, sum + num[ind], num, ds, k, ans);
    ds.pop_back();
    findSS(ind + 1, sum, num, ds, k, ans);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findSS(0, 0, arr, ds, k, ans);

    return ans;
}