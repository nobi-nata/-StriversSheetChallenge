#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m)
{
    long long ans = 1;
    long long xx = x;
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            xx = (xx * xx) % m;
            n = n / 2;
        }
        else
        {
            ans = (ans * xx) % m;
            n = n - 1;
        }
    }
    return ans;
}