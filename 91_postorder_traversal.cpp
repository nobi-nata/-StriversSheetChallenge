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
//RECURSIVE
//TC - O(N)
//SC - O(N)
void postO(TreeNode *root, vector<int> &postorder)
{
    if (root == NULL)
        return;
    postO(root->left, postorder);
    postO(root->right, postorder);
    postorder.push_back(root->data);
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> postorder;
    postO(root, postorder);
    return postorder;
}

//ITERATIVE  - using 2 stacks
//TC - o(n)
//SC - o(2n)

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> postorder;
    if (root == NULL)
        return postorder;
    stack<TreeNode *> st1;
    stack<TreeNode *> st2;
    st1.push(root);
    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if (root->left != NULL)
            st1.push(root->left);
        if (root->right != NULL)
            st1.push(root->right);
    }
    while (!st2.empty())
    {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    return postorder;
}

// ITERATIVE  - using 1 stack
// TC - o(2n)
// SC - o(n)

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> postorder;
    if (root == NULL)
        return postorder;
    stack<TreeNode *> st;
    TreeNode *cur = root;
    while (cur != NULL || !st.empty())
    {
        if (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            TreeNode *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else
            {
                cur = temp;
            }
        }
    }

    return postorder;
}