//SpACE - 2n
#include <bits/stdc++.h>
// Implement class for minStack.

class minStack
{
    // Write your code here.
    stack<pair<int, int>> st;

public:
    // Constructor
    minStack()
    {
        // Write your code here.
    }

    // Function to add another element equal to num at the top of stack.
    void push(int num)
    {
        if (!st.empty())
        {
            if (num < st.top().second)
                st.push({num, num});
            else
                st.push({num, st.top().second});
        }
        else
        {
            st.push({num, num});
        }
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        if (st.empty())
            return -1;
        int ele = st.top().first;
        st.pop();
        return ele;
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top()
    {
        if (st.empty())
            return -1;
        return st.top().first;
    }

    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin()
    {
        if (st.empty())
            return -1;
        return st.top().second;
    }
};


//SPACE - n
#include <bits/stdc++.h>
// Implement class for minStack.

class minStack
{
    // Write your code here.
    stack<long> st;
    long mini;

public:
    // Constructor
    minStack()
    {
        mini = LONG_MAX;
    }

    // Function to add another element equal to num at the top of stack.
    void push(int num)
    {
        if (!st.empty())
        {
            if (num < mini)
            {
                st.push(2 * num - mini);
                mini = num;
            }
            else
                st.push(num);
        }
        else
        {
            st.push(num);
            mini = num;
        }
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        if (st.empty())
            return -1;
        else
        {
            int ele = st.top();
            if (st.top() < mini)
            {
                ele = mini;
                mini = 2 * mini - st.top();
            }
            st.pop();
            return ele;
        }
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top()
    {
        if (st.empty())
            return -1;
        if (st.top() < mini)
            return mini;
        else
            return st.top();
    }

    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin()
    {
        if (st.empty())
            return -1;
        return mini;
    }
};