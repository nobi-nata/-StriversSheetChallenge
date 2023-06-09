#include <bits/stdc++.h>

bool isPalindrome(string &s, int st, int e)
{
    while (st <= e)
    {
        if (s[st++] != s[e--])
        {
            return false;
        }
    }
    return true;
}

void pp(int ind, string &s, vector<string> &ds, vector<vector<string>> &ans)
{

    if (ind == s.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = ind; i < s.size(); i++)
    {
        if (isPalindrome(s, ind, i))
        {
            ds.push_back(s.substr(ind, i - ind + 1));
            pp(i + 1, s, ds, ans);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s)
{
    vector<vector<string>> ans;
    vector<string> ds;
    pp(0, s, ds, ans);
    return ans;
}