#include <bits/stdc++.h>

string fourSum(vector<int> a, int t, int n)
{
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && a[i] == a[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j != i + 1 && a[j] == a[j - 1])
                continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = a[i] + a[j];
                sum += a[k] + a[l];
                if (sum == t)
                {
                    return "Yes";
                }
                else if (sum < t)
                {
                    k++;
                    while (k < l && a[k] == a[k - 1])
                        k++;
                }
                else
                {
                    l--;
                    while (k < l && a[l] == a[l + 1])
                        l--;
                }
            }
        }
    }
    return "No";
}