#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
    int n = prices.size();
    int profit = 0;
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, prices[i]);
        profit = max(profit, prices[i] - mini);
    }
    return profit;
}