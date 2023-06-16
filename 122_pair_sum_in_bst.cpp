#include <bits/stdc++.h>
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
class BSTIterator
{

    stack<BinaryTreeNode<int> *> st;
    bool reverse = true;

public:
    BSTIterator(BinaryTreeNode<int> *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        BinaryTreeNode<int> *node = st.top();
        st.pop();
        if (!reverse)
            pushAll(node->right);
        else
            pushAll(node->left);
        return node->data;
    }

    bool hasNext()
    {
        return !st.empty();
    }

    void pushAll(BinaryTreeNode<int> *node)
    {
        for (; node != NULL;)
        {
            st.push(node);
            if (reverse == NULL)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
    }
};
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    if (!root)
        return false;
    BSTIterator l(root, false);
    BSTIterator r(root, true);

    int i = l.next();
    int j = r.next();
    while (i < j)
    {
        if (i + j == k)
            return true;
        else if (i + j < k)
            i = l.next();
        else
            j = r.next();
    }
    return false;
}