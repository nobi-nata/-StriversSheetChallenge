#include <bits/stdc++.h>
//BRUTE
vector<int> findSpans(vector<int> &price)
{
    vector<int> ans;
    int n = price.size();
    for (int i = 0; i < n; i++)
    {
        int cnt = 0, ele = price[i], j = i;
        while (j >= 0 && ele >= price[j--])
            cnt++;
        ans.push_back(cnt);
    }
    return ans;
}

//better
#include <bits/stdc++.h>
vector<int> findSpans(vector<int> &price)
{
    int n = price.size();
    vector<int> ans(n, 1);
    for (int i = 0; i < n; i++)
    {
        int ele = price[i], j = i - 1;
        while (j >= 0 && ele >= price[j])
        {
            ans[i] += ans[j];
            j = j - ans[j];
        }
    }
    return ans;
}

//using stack
#include <bits/stdc++.h>
vector<int> findSpans(vector<int> &price)
{
    int n = price.size();
    vector<int> ans;
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        int ele = price[i];
        int cnt = 1;
        while (!st.empty() && ele >= st.top().first)
        {
            cnt += st.top().second;
            st.pop();
        }
        st.push({ele, cnt});
        ans.push_back(cnt);
    }
    return ans;
}
