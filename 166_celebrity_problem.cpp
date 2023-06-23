#include <bits/stdc++.h>
/*
    This is signature of helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B);
    Function 'knows(A, B)' will returns "true" if the person having
    id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n)
{
    // int ind = -1;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (knows(0, i) == true)
            st.push(i);
    }
    if (st.empty())
    {
        int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            if (knows(i, 0) == false)
                break;
            else
                cnt++;
        }
        if (cnt == n - 1)
            return 0;
    }
    while (!st.empty())
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (knows(st.top(), i) == true)
                break;
            else
                cnt++;
        }
        if (cnt == n)
            return st.top();
        st.pop();
    }
    return -1;
}