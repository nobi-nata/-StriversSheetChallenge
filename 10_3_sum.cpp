#include <bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int> a, int n, int K)
{
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && a[i] == a[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            long long sum = a[i];
            sum += a[k];
            sum += a[j];
            if (sum == K)
            {
                vector<int> temp = {a[i], a[j], a[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && a[j] == a[j - 1])
                    j++;
                while (j < k && a[k] == a[k + 1])
                    k--;
            }
            else if (sum < K)
            {
                j++;
                while (j < k && a[j] == a[j - 1])
                    j++;
            }
            else
            {
                k--;
                while (j < k && a[k] == a[k + 1])
                    k--;
            }
        }
    }
    return ans;
}