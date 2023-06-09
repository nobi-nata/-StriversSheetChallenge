#include <bits/stdc++.h>

void findc(int ind, int sum, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans, int n)
{
    if (sum == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = ind; i < n; i++)
    {
        if (i != ind && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > sum)
            break;
        ds.push_back(arr[i]);
        findc(i + 1, sum - arr[i], arr, ds, ans, n);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    findc(0, target, arr, ds, ans, n);

    return ans;
}
