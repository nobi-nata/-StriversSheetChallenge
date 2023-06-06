vector<vector<int>> mergeIntervals(vector<vector<int>> &a)
{
    sort(a.begin(), a.end());
    int n = a.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int s = a[i][0];
        int e = a[i][1];
        if (!ans.empty() && s <= ans.back()[1])
        {
            ans.back()[1] = max(ans.back()[1], e);
        }
        else
        {
            ans.push_back({s, e});
        }
    }
    return ans;
}
