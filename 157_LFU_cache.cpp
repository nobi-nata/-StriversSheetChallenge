#include <bits/stdc++.h>
struct Node
{
    int key, value, cnt;
    Node *next;
    Node *prev;
    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        cnt = 1;
    }
};
struct List
{
    int size;
    Node *tail;
    Node *head;
    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addNode(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        tail->prev = node;
        size++;
    }

    void removeNode(Node *node)
    {
        Node *delprev = node->prev;
        Node *delnext = node->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};
class LFUCache
{
    map<int, Node *> keyNode;
    map<int, List *> freqListMap;
    int maxCap;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity)
    {
        maxCap = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqList(Node *node)
    {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
        {
            minFreq++;
        }
        List *nextHigherFreqList = new List();
        if (freqListMap.find(node->cnt + 1) != freqListMap.end())
        {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }
        node->cnt += 1;
        nextHigherFreqList->addNode(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqList(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (maxCap == 0)
            return;
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqList(node);
        }
        else
        {
            if (curSize == maxCap)
            {
                List *list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                list->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            List *listfreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end())
            {
                listfreq = freqListMap[minFreq];
            }
            Node *node = new Node(key, value);
            keyNode[key] = node;
            listfreq->addNode(node);
            freqListMap[minFreq] = listfreq;
        }
    }
};
