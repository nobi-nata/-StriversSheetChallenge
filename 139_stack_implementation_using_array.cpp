#include <bits/stdc++.h>
// Stack class.
class Stack
{

public:
//     int size;
//     int *arr;
//     int top;

// public:
//     Stack()
//     {
//         top = -1;
//         size = 1000;
//         arr = new int[size];
//     }
    int arr[1000];
    int topi;
    int n;
    Stack(int capacity)
    {
        n = capacity;
        topi = -1;
    }

    void push(int num)
    {
        if (topi < n - 1)
            arr[++topi] = num;
    }

    int pop()
    {
        if (topi != -1)
        {
            topi--;
            return arr[topi + 1];
        }
        return -1;
    }

    int top()
    {
        if (topi != -1)
        {
            return arr[topi];
        }
        return -1;
    }

    int isEmpty()
    {
        if (topi == -1)
            return 1;
        return 0;
    }

    int isFull()
    {
        if (topi == n - 1)
            return 1;
        else
            return 0;
    }
};