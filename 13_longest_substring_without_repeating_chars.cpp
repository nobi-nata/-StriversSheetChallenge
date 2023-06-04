#include <bits/stdc++.h>
int uniqueSubstrings(string s)
{
    int len = 0;
    int n = s.size();
    int left = 0;
    int right = 0;
    map<char, int> mpp;
    while (right < n)
    {
        if (mpp.find(s[right]) != mpp.end())
        {
            left = max(left, mpp[s[right]] + 1);
        }

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
    }
    return len;
}