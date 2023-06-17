#include <bits/stdc++.h>
void sortStack(stack<int> &stack)
{
    vector<int> s;
    while (!stack.empty())
    {
        s.push_back(stack.top());
        stack.pop();
    }
    sort(s.begin(), s.end());
    for (auto i : s)
    {
        stack.push(i);
    }
}


//recursive
#include <bits/stdc++.h>

void sortInsert(stack<int> &st, int num)
{
    if (st.empty() || (!st.empty() && st.top() < num))
    {
        st.push(num);
        return;
    }

    int n = st.top();
    st.pop();

    sortInsert(st, num);

    st.push(n);
}

void sortStack(stack<int> &stack)
{
    if (stack.empty())
        return;

    int num = stack.top();
    stack.pop();

    sortStack(stack);

    sortInsert(stack, num);
}