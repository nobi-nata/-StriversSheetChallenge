#include <bits/stdc++.h>

struct meeting
{
    int s;
    int e;
};

bool comparator(struct meeting m1, meeting m2)
{
    if (m1.e < m2.e)
        return true;
    else if (m1.e > m2.e)
        return false;
    else if (m1.s < m2.s)
        return true;
    else
        return false;
}

int maximumActivities(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    int n = start.size();
    struct meeting meet[n];
    for (int i = 0; i < n; i++)
    {
        meet[i].s = start[i];
        meet[i].e = end[i];
    }

    sort(meet, meet + n, comparator);

    int limit = meet[0].e;
    int cnt = 1;

    for (int i = 1; i < n; i++)
    {
        if (meet[i].s >= limit)
        {
            limit = meet[i].e;
            cnt++;
        }
    }

    return cnt;
}