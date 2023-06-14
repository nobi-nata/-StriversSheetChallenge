#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int n = q.size();
        int nmin = q.front().second;
        int last, first;
        for (int i = 0; i < n; i++)
        {
            int index = q.front().second - nmin;
            TreeNode<int> *node = q.front().first;
            q.pop();
            if (i == 0)
                first = index;
            if (i == n - 1)
                last = index;
            if (node->left != NULL)
                q.push({node->left, 2 * index + 1});
            if (node->right != NULL)
                q.push({node->right, 2 * index + 2});
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}


// ANSWER TO QUESTION WHERE NULL NODE ARE EXCLUDED IN WIDTH CALCULATION

int getMaxWidth(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode<int> *node = q.front();
            q.pop();

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        ans = max(ans, n);
    }
    return ans;
}