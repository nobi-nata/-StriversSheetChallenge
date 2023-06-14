#include <bits/stdc++.h>
//TC - O(2^N*N)
//SC - O(1)
//Using bit manupilation
vector<vector<int>> pwset(vector<int> v)
{
    vector<vector<int>> ans;
    int n = v.size();

    for (int num = 0; num < (1 << n); num++)
    {
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (num & (1 << i))
                temp.push_back(v[i]);
        }
        ans.push_back(temp);
    }
    return ans;
}


//Using backtracking
#include <bits/stdc++.h>
void solve(int ind, vector<int> &v, vector<int> &temp, vector<vector<int>> &ans)
{
    if (ind == v.size())
    {
        ans.push_back(temp);
        return;
    }

    temp.push_back(v[ind]);
    solve(ind + 1, v, temp, ans);
    temp.pop_back();
    solve(ind + 1, v, temp, ans);
}

vector<vector<int>> pwset(vector<int> v)
{
    vector<vector<int>> ans;
    int n = v.size();
    vector<int> temp;
    solve(0, v, temp, ans);
    return ans;
}