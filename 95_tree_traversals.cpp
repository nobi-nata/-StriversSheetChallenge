#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> ans;
    vector<int> in;
    vector<int> pre;
    vector<int> post;
    if (root == NULL)
        return ans;
    stack<pair<BinaryTreeNode<int> *, int>> st;
    st.push({root, 1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        BinaryTreeNode<int> *node = it.first;
        int num = it.second;
        if (num == 1)
        {
            pre.push_back(node->data);
            num++;
            st.push({node, num});
            if (node->left != NULL)
                st.push({node->left, 1});
        }
        else if (num == 2)
        {
            in.push_back(node->data);
            num++;
            st.push({node, num});
            if (node->right != NULL)
                st.push({node->right, 1});
        }
        else
        {
            post.push_back(node->data);
        }
    }
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}