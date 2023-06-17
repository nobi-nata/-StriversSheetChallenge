#include <bits/stdc++.h>

class LRUCache
{
public:
    class node
    {
    public:
        int key;
        int value;
        node *next;
        node *prev;
        node(int key_, int value_)
        {
            key = key_;
            value = value_;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    int cap;
    unordered_map<int, node *> mpp;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node *res)
    {
        node *temp = head->next;
        res->next = temp;
        res->prev = head;
        head->next = res;
        temp->prev = res;
    }

    void deletenode(node *res)
    {
        node *delprev = res->prev;
        node *delnext = res->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key)
    {
        if (mpp.find(key) != mpp.end())
        {
            node *res = mpp[key];
            int ans = res->value;
            mpp.erase(key);
            deletenode(res);
            addnode(res);
            mpp[key] = head->next;
            return ans;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mpp.find(key) != mpp.end())
        {
            node *res = mpp[key];
            mpp.erase(key);
            deletenode(res);
        }
        if (cap == mpp.size())
        {
            mpp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        mpp[key] = head->next;
    }
};
