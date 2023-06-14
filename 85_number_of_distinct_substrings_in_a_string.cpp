//using set
//TC - O(N^2 log(M))
//SC - O(N^3)
#include <bits/stdc++.h>
int distinctSubstring(string &word)
{
    set<string> st;
    for (int i = 0; i < word.size(); i++)
    {
        string str = "";
        for (int j = i; j < word.size(); j++)
        {
            str = str + word[j];
            st.insert(str);
        }
    }
    return st.size();
}

//USING TRIE
//TC - O(N^2)
#include <bits/stdc++.h>

struct Node
{
    Node *links[26];

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
};

int distinctSubstring(string &word)
{
    int n = word.size();
    int cnt = 0;
    Node *root = new Node();
    for (int i = 0; i < n; i++)
    {
        Node *node = root;
        for (int j = i; j < n; j++)
        {
            if (!node->containsKey(word[j]))
            {
                cnt++;
                node->put(word[j], new Node());
            }
            node = node->get(word[j]);
        }
    }

    return cnt;
}
