#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n)
{
    int el;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!cnt)
        {
            cnt = 1;
            el = arr[i];
        }
        else if (arr[i] == el)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (el == arr[i])
            cnt++;
    }
    if (cnt > n / 2)
        return el;
    return -1;
}