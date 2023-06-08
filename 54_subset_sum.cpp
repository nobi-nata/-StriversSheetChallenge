#include <bits/stdc++.h>

void findSS(int ind, int sum, vector<int> &num, vector<int> &sumStore)
{
    int n = num.size();
    if (ind == n)
    {
        sumStore.push_back(sum);
        return;
    }

    findSS(ind + 1, sum + num[ind], num, sumStore);

    findSS(ind + 1, sum, num, sumStore);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> sumStore;
    findSS(0, 0, num, sumStore);
    sort(sumStore.begin(), sumStore.end());
    return sumStore;
}