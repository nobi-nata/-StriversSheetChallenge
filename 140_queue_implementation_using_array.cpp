#include <bits/stdc++.h>
class Queue
{
    int *arr;
    int cnt;
    int n;
    int f;
    int rear;

public:
    Queue()
    {
        // Implement the Constructor
        n = 1000;
        arr = new int[n];
        cnt = 0;
        f = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        if (cnt == 0)
            return true;
        return false;
    }

    void enqueue(int data)
    {
        if (cnt == n)
            return;
        arr[rear % n] = data;
        rear++;
        cnt++;
    }

    int dequeue()
    {
        if (cnt == 0)
            return -1;
        int ele = arr[f % n];
        arr[f % n] = -1;
        f++;
        cnt--;
        return ele;
    }

    int front()
    {
        if (cnt == 0)
            return -1;
        return arr[f % n];
    }
};