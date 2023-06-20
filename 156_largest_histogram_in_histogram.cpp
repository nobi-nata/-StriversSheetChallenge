#include <bits/stdc++.h>
//BRUTE
int rm(int i, vector<int> &heights, int n)
{
    int e = heights[i];
    while (i < n - 1)
    {
        if (e <= heights[i + 1])
        {
            i++;
        }
        else
        {
            return i;
        }
    }
    return i;
}
int lm(int i, vector<int> &heights)
{
    int e = heights[i];
    while (i > 0)
    {
        if (e <= heights[i - 1])
        {
            i--;
        }
        else
        {
            return i;
        }
    }
    return i;
}

int largestRectangle(vector<int> &heights)
{
    int n = heights.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int leftmin = lm(i, heights);
        int rightmin = rm(i, heights, n);
        int ans = (rightmin - leftmin + 1) * heights[i];
        maxi = max(ans, maxi);
    }
    return maxi;
}


//BETTER
#include <bits/stdc++.h>

int largestRectangle(vector<int> &heights)
{
    int n = heights.size();
    int left[n], right[n];
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
            left[i] = 0;
        else
            left[i] = st.top() + 1;
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
            right[i] = n - 1;
        else
            right[i] = st.top() - 1;
        st.push(i);
    }

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int ans = (right[i] - left[i] + 1) * heights[i];
        maxi = max(ans, maxi);
    }
    return maxi;
}

//OPTIMAL
#include <bits/stdc++.h>

int largestRectangle(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int maxi = 0;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
        {
            int height = heights[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = (i - st.top() - 1);
            maxi = max(maxi, height * width);
        }
        st.push(i);
    }

    return maxi;
}