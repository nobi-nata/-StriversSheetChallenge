#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    int p = m + n - 1;
    int i = m - 1;
    int j = n - 1;
    while (i >= 0 && j >= 0)
    {
        if (arr1[i] > arr2[j])
        {
            arr1[p] = arr1[i];
            i--;
            p--;
        }
        else
        {
            arr1[p] = arr2[j];
            j--;
            p--;
        }
    }
    while (i >= 0)
    {
        arr1[p] = arr1[i];
        i--;
        p--;
    }
    while (j >= 0)
    {
        arr1[p] = arr2[j];
        j--;
        p--;
    }

    return arr1;
}