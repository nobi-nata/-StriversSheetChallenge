#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    int pre = -1;
    int suc = -1;
    BinaryTreeNode<int> *p = root;
    BinaryTreeNode<int> *s = root;
    while (s != NULL)
    {
        if (s->data <= key)
        {
            s = s->right;
        }
        else
        {
            suc = s->data;
            s = s->left;
        }
    }
    while (p != NULL)
    {
        if (p->data >= key)
        {
            p = p->left;
        }
        else
        {
            pre = p->data;
            p = p->right;
        }
    }
    return {pre, suc};
}
