#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n)
{
    vector<vector<long long int>> ans1;
    for (int j = 1; j <= n; j++)
    {
        long long int ans = 1;
        vector<long long int> temp;
        temp.push_back(ans);
        for (int i = 1; i < j; i++)
        {
            ans = ans * (long long int)(j - i);
            ans = ans / (long long int)i;
            temp.push_back(ans);
        }
        ans1.push_back(temp);
    }
    return ans1;
}
