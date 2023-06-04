#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector<int> a)
{
    int n = a.size();
    map<long long, int> mpp;
    int mlen = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == 0)
        {
            mlen = max(mlen, i + 1);
        }
        long long rem = sum;
        if (mpp.find(rem) != mpp.end())
        {
            int len = i - mpp[rem];
            mlen = max(mlen, len);
        }
        if (mpp.find(sum) == mpp.end())
        {
            mpp[sum] = i;
        }
    }
    return mlen;
}