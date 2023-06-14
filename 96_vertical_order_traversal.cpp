#include <bits/stdc++.h>
/************************************************************

Following is the Binary Tree node class

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    if (root == NULL)
        return {};
    queue<pair<TreeNode<int> *, pair<int, int>>> q;
    map<int, map<int, vector<int>>> mpp;

    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode<int> *node = it.first;
        int v = it.second.first;
        int level = it.second.first;

        mpp[v][level].push_back(node->data);
        if (node->left != NULL)
            q.push({node->left, {v - 1, level + 1}});
        if (node->right != NULL)
            q.push({node->right, {v + 1, level + 1}});
    }
    vector<int> ans;
    for (auto it : mpp)
    {
        for (auto i : it.second)
        {
            ans.insert(ans.end(), i.second.begin(), i.second.end());
        }
    }
    return ans;
}