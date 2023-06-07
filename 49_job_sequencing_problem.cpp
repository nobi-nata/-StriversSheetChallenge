#include <bits/stdc++.h>

bool comparator(vector<int> j1, vector<int> j2)
{
    return j1[1] > j2[1] || (j1[1] == j2[1] && j1[0] >= j2[0]);
}

int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), comparator);

    int m = 0;
    for (int i = 0; i < n; i++)
    {
        m = max(m, jobs[i][0]);
    }

    int dp[m + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i] = -1;
    }

    int profit = 0;
    for (int i = 0; i < jobs.size(); i++)
    {
        int d = jobs[i][0];
        for (int j = d; j > 0; j--)
        {
            if (dp[j] == -1)
            {
                dp[j] = 1;
                profit += jobs[i][1];
                break;
            }
        }
    }

    return profit;
}
