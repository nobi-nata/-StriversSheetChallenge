#include <bits/stdc++.h>

bool isValidParenthesis(string s)
{
    int n = s.size();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
                return false;
            char ch = st.top();
            st.pop();
            if ((ch == '(' and s[i] == ')') or (ch == '{' and s[i] == '}') or
                (ch == '[' and s[i] == ']'))
                continue;
            else
                return false;
        }
    }
    if (st.empty())
        return true;
    return false;
}