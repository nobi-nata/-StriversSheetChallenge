#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int> *root)
{
    return (!root->left && !root->right);
}

void addLeftBoundary(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *node = root->left;
    while (node != NULL)
    {
        if (!isLeaf(node))
            res.push_back(node->data);
        if (node->left != NULL)
            node = node->left;
        else
            node = node->right;
    }
}

void addLeafs(TreeNode<int> *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left != NULL)
        addLeafs(root->left, res);
    if (root->right != NULL)
        addLeafs(root->right, res);
}

void addRightBoundary(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *node = root->right;
    stack<int> st;
    while (node != NULL)
    {
        if (!isLeaf(node))
            st.push(node->data);
        if (node->right != NULL)
            node = node->right;
        else
            node = node->left;
    }
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    if (!isLeaf(root))
        res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeafs(root, res);
    addRightBoundary(root, res);
    return res;
}