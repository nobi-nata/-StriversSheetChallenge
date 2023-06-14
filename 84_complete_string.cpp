#include <bits/stdc++.h>

//TC - O(2*N*len)

struct Node
{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    bool isEnd()
    {
        return flag;
    }

    void setEnd()
    {
        flag = true;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkIfIsPrefix(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
            if (node->flag == false)
                return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a)
{
    Trie t;
    for (auto it : a)
    {
        t.insert(it);
    }

    string longest = "";
    for (int i = 0; i < a.size(); i++)
    {
        if (t.checkIfIsPrefix(a[i]))
        {
            if (a[i].size() > longest.size())
            {
                longest = a[i];
            }
            else if (a[i].size() == longest.size() && a[i] < longest)
            {
                longest = a[i];
            }
        }
    }

    if (longest.size() == 0)
        return "None";
    return longest;
}