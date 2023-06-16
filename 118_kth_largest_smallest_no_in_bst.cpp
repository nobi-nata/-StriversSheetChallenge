#include <bits/stdc++.h>
/************************************************************
    Following is the Binary Search Tree node structure

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

// LARGEST
void inorder(TreeNode<int> *root, int &n)
{
    if (root == NULL)
        return;
    inorder(root->left, n);
    n++;
    inorder(root->right, n);
}

int kthLarge(TreeNode<int> *root, int &k)
{
    if (root == NULL)
        return -1;
    int left = kthLarge(root->left, k);
    if (left != -1)
        return left;
    k--;
    if (k == 0)
        return root->data;
    return kthLarge(root->right, k);
}

int KthLargestNumber(TreeNode<int> *root, int k)
{
    int n = 0;
    inorder(root, n);
    if (k > n)
        return -1;
    k = n - k + 1;
    return kthLarge(root, k);
}


// SMALLEST

int kthSmall(TreeNode *root, int &k)
{
    if (root == NULL)
        return -1;
    int left = kthSmall(root->left, k);
    if (left != -1)
        return left;
    k--;
    if (k == 0)
        return root->val;
    return kthSmall(root->right, k);
}

int kthSmallest(TreeNode *root, int k)
{
    return kthSmall(root, k);
}

