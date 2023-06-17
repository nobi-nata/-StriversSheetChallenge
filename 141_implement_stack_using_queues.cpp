//using 2 queues
#include <bits/stdc++.h>
class Stack
{
    // Define the data members.
    queue<int> q1;
    queue<int> q2;

public:
    Stack()
    {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        return q1.size();
    }

    bool isEmpty()
    {
        return q1.empty();
    }

    void push(int element)
    {
        q2.push(element);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop()
    {
        if (q1.size() == 0)
            return -1;
        int n = q1.front();
        q1.pop();
        return n;
    }

    int top()
    {
        if (q1.size() == 0)
            return -1;
        return q1.front();
    }
};

//using single queue
#include <bits/stdc++.h>
class Stack
{
    // Define the data members.
    queue<int> q;

public:
    Stack()
    {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        return q.size();
    }

    bool isEmpty()
    {
        return q.empty();
    }

    void push(int element)
    {
        q.push(element);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        if (q.size() == 0)
            return -1;
        int n = q.front();
        q.pop();
        return n;
    }

    int top()
    {
        if (q.size() == 0)
            return -1;
        return q.front();
    }
};