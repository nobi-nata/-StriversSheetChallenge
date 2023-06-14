#include <bits/stdc++.h>
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

//RECURSIVE SOLUTION
//TC - o(N)
//SC - o(N)
void preO(TreeNode *root, vector<int> &preorder)
{
    if (root == NULL)
        return;
    preorder.push_back(root->data);
    preO(root->left, preorder);
    preO(root->right, preorder);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> preorder;
    preO(root, preorder);
    return preorder;
}

//ITERATIVE SOLUTION
//TC - O(N)
//SC - O(N)
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> preorder;
    if (root == NULL)
        return preorder;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        preorder.push_back(root->data);
        if (root->right != NULL)
        {
            st.push(root->right);
        }
        if (root->left != NULL)
        {
            st.push(root->left);
        }
    }
    return preorder;
}