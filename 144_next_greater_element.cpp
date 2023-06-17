#include <bits/stdc++.h>
//brute
//TC - O(N^2)
vector<int> nextGreater(vector<int> &arr, int n)
{
    vector<int> nge(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                nge[i] = arr[j];
                break;
            }
        }
    }
    return nge;
}

//optimised
#include <bits/stdc++.h>

vector<int> nextGreater(vector<int> &arr, int n)
{
    vector<int> nge(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] >= st.top())
            st.pop();
        if (!st.empty())
            nge[i] = st.top();
        st.push(arr[i]);
    }
    return nge;
}

//variant-2 -- circular-next-greater
#include <bits/stdc++.h>

vector<int> nextGreater(vector<int> &arr, int n)
{
    vector<int> nge(n, -1);
    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i % n] >= st.top())
            st.pop();
        if (i < n && !st.empty())
            nge[i] = st.top();
        st.push(arr[i % n]);
    }
    return nge;
}