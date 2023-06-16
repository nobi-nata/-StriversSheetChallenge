#include <bits/stdc++.h>
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public :
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode<int> *root)
{
    stack<BinaryTreeNode<int> *> st;
    stack<BinaryTreeNode<int> *> ts;
    st.push(root);
    while (!st.empty())
    {
        while (!st.empty())
        {
            auto node = st.top();
            st.pop();
            ts.push(node);
            if (!st.empty())
                node->next = st.top();
        }
        while (!ts.empty())
        {
            auto node = ts.top();
            ts.pop();
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
    }
}