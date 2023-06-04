#include <bits/stdc++.h>
vector<int> nextPermutation(vector<int> &a, int n)
{
    int ind = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            ind = i;
            break;
        }
    }
    if (ind != -1)
    {
        for (int i = n - 1; i >= ind; i--)
        {
            if (a[i] > a[ind])
            {
                swap(a[ind], a[i]);
                break;
            }
        }
    }
    reverse(a.begin() + ind + 1, a.end());
    return a;
}