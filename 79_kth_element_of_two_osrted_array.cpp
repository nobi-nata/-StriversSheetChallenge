//BRUTE FORCE 
//TC - O(N1+N2)
//SC - O(1)
int ninjaAndLadoos(vector<int> &a, vector<int> &b, int n1, int n2, int k)
{

    int p = 0;
    int q = 0;
    int cnt = 0;
    if (k > (n1 + n2))
        return 0;
    int ele = 0;

    while (p < n1 && q < n2)
    {

        if (a[p] < b[q])
        {
            cnt++;
            ele = a[p];
            p++;
        }
        else
        {
            cnt++;
            ele = b[q];
            q++;
        }
        if (cnt == k)
        {
            return ele;
        }
    }
    while (p < n1)
    {
        cnt++;
        ele = a[p];
        p++;
        if (cnt == k)
        {
            return ele;
        }
    }
    while (q < n2)
    {
        cnt++;
        ele = b[q];
        q++;
        if (cnt == k)
        {
            return ele;
        }
    }
}

//BRUTE-OPTIMISED
//TC - O(MIN(N1,N2,K))
//SC - O(1)
int ninjaAndLadoos(vector<int> &a, vector<int> &b, int n1, int n2, int k)
{

    int p = 0;
    int q = 0;
    int cnt = 0;
    if (k > (n1 + n2))
        return 0;
    int ele = 0;

    while (p < n1 && q < n2)
    {

        if (a[p] < b[q])
        {
            cnt++;
            ele = a[p];
            p++;
        }
        else
        {
            cnt++;
            ele = b[q];
            q++;
        }
        if (cnt == k)
        {
            return ele;
        }
    }
    if (p < n1)
    {
        return a[p + k - cnt - 1];
    }
    else
    {
        return b[q + k - cnt - 1];
    }
}


// OPTIMAL
// TC - O(log(min(n1,n2)))
// SC - O(1)
#include <bits/stdc++.h>

int ninjaAndLadoos(vector<int> &a, vector<int> &b, int n1, int n2, int k)
{
    if (n1 > n2)
        return ninjaAndLadoos(b, a, n2, n1, k);
    // edge-cases
    int low = max(0, k - n2);
    int high = min(n1, k);

    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;

        int l1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];
        int r1 = cut1 == n1 ? INT_MAX : a[cut1];
        int r2 = cut2 == n2 ? INT_MAX : b[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 0;
}