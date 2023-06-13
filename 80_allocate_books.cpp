#include <bits/stdc++.h>

//TC - O(NlogN)
//SC - O(1)
bool isPossible(vector<int> arr, int stud, long long limit)
{
    int cnt = 1;
    long long sumGot = 0;
    int m = arr.size();
    for (int i = 0; i < m; i++)
    {
        if (arr[i] > limit)
            return false;
        if (sumGot + arr[i] > limit)
        {
            cnt++;
            sumGot = arr[i];
        }
        else
        {
            sumGot += arr[i];
        }
    }
    if (cnt <= stud)
        return true;
    return false;
}

long long ayushGivesNinjatest(int stud, int m, vector<int> books)
{
    int l = books[0];
    long long high = 0;
    for (int i = 0; i < m; i++)
    {
        high += books[i];
        l = min(l, books[i]);
    }
    long long low = l;
    long long ans = -1;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (isPossible(books, stud, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}