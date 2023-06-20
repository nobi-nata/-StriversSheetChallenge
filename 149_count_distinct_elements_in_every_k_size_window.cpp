#include <bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k)
{
    vector<int> ans;
    unordered_map<int, int> mpp;
    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        mpp[arr[i]]++;
    }
    ans.push_back(mpp.size());
    int j = 0;
    for (int i = k; i < arr.size(); i++)
    {
        mpp[arr[i]]++;
        mpp[arr[j]]--;
        if (mpp[arr[j]] == 0)
            mpp.erase(arr[j]);
        ans.push_back(mpp.size());
        j++;
    }
    return ans;
}
