#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &a, int n)
{
    int longest = 1;
    if (n == 0)
        return 0;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }
    for (auto i : st)
    {
        if (st.find(i - 1) == st.end())
        {
            int cnt = 1;
            int x = i;
            while (st.find(x + 1) != st.end())
            {
                cnt++;
                x++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}