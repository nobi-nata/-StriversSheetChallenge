#include <bits/stdc++.h>
struct Node
{
    Node *links[2];

    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }

    Node *get(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Trie
{
public:
    Node *root;

    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int q = queries.size();

    vector<pair<int, pair<int, int>>> oQ;
    for (int i = 0; i < q; i++)
    {
        oQ.push_back({queries[i][1], {queries[i][0], i}});
    }
    vector<int> a(q, 0);
    sort(oQ.begin(), oQ.end());

    Trie t;
    int ind = 0;
    for (int i = 0; i < q; i++)
    {
        int ai = oQ[i].first;
        int xi = oQ[i].second.first;
        int p = oQ[i].second.second;

        while (ind < n && arr[ind] <= ai)
        {
            t.insert(arr[ind]);
            ind++;
        }
        if (ind == 0)
            a[p] = -1;
        else
            a[p] = t.getMax(xi);
    }
    return a;
}