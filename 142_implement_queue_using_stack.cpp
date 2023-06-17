#include <bits/stdc++.h>

class Queue
{
    // Define the data members(if any) here.
    stack<int> s1;
    stack<int> s2;

public:
    Queue()
    {
        // Initialize your data structure here.
    }

    void enQueue(int val)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deQueue()
    {
        if (s1.empty())
            return -1;
        int n = s1.top();
        s1.pop();
        return n;
    }

    int peek()
    {
        if (s1.empty())
            return -1;
        return s1.top();
    }

    bool isEmpty()
    {
        if (s1.empty())
            return true;
        return false;
    }
};

//amortised TC
#include <bits/stdc++.h>

class Queue
{
    // Define the data members(if any) here.
    stack<int> s1;
    stack<int> s2;

public:
    Queue()
    {
        // Initialize your data structure here.
    }

    void enQueue(int val)
    {
        s1.push(val);
    }

    int deQueue()
    {
        if (!s2.empty())
        {
            int n = s2.top();
            s2.pop();
            return n;
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            if (s2.empty())
                return -1;
            int n = s2.top();
            s2.pop();
            return n;
        }
    }

    int peek()
    {
        if (!s2.empty())
        {
            return s2.top();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            if (s2.empty())
                return -1;
            return s2.top();
        }
    }

    bool isEmpty()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            if (s2.empty())
                return true;
        }
        return false;
    }
};