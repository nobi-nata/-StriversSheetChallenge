#include <bits/stdc++.h>
bool areAnagram(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();
    n = max(n, m);
    map<char, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[str1[i]]++;
        mpp[str2[i]]++;
    }
    for (auto i : mpp)
    {
        if (i.second < 2)
            return false;
    }
    return true;
}