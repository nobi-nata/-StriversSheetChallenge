#include <bits/stdc++.h>

bool comparator(pair<int, int> i1, pair<int, int> i2)
{
    double r1 = double(i1.second) / double(i1.first);
    double r2 = double(i2.second) / double(i2.first);
    return (r1 > r2);
}

double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), comparator);

    int iW = 0;
    double mV = 0;
    for (int i = 0; i < n; i++)
    {
        if (iW + items[i].first < w)
        {
            iW += items[i].first;
            mV += items[i].second;
        }
        else
        {
            double remain = w - iW;
            mV += double(items[i].second) / double(items[i].first) * remain;
            break;
        }
    }
    return mV;
}