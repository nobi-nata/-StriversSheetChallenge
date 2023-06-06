#include <bits/stdc++.h>
long getTrappedWater(long *h, int n)
{
    long left = 0;
    long right = n - 1;
    long long res = 0;
    long ml = 0;
    long mr = 0;
    while (left <= right)
    {
        if (h[left] <= h[right])
        {
            if (h[left] >= ml)
                ml = h[left];
            else
                res += ml - h[left];
            left++;
        }
        else
        {
            if (h[right] >= mr)
                mr = h[right];
            else
                res += mr - h[right];
            right--;
        }
    }
    return long(res);
}