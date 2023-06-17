vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> nse(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                nse[i] = arr[j];
                break;
            }
        }
    }
    return nse;
}

//optimised
#include <bits/stdc++.h>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> nse(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] <= st.top())
        {
            st.pop();
        }
        if (!st.empty())
            nse[i] = st.top();
        st.push(arr[i]);
    }
    return nse;
}