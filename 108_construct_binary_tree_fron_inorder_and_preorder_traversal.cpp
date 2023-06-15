#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int> *buildBT(vector<int> &inorder, int inStart, int inEnd, vector<int> &preorder, int preStart, int preEnd, map<int, int> &mpp)
{
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    TreeNode<int> *node = new TreeNode<int>(preorder[preStart]);
    int inRoot = mpp[node->data];
    int numLeft = inRoot - inStart;

    node->left = buildBT(inorder, inStart, inRoot - 1, preorder, preStart + 1, preEnd + numLeft, mpp);
    node->right = buildBT(inorder, inRoot + 1, inEnd, preorder, preStart + 1 + numLeft, preEnd, mpp);
    return node;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int inStart = 0;
    int inEnd = inorder.size() - 1;
    int preStart = 0;
    int preEnd = preorder.size() - 1;

    map<int, int> mpp;
    for (int i = 0; i <= inEnd; i++)
    {
        mpp[inorder[i]] = i;
    }

    return buildBT(inorder, inStart, inEnd, preorder, preStart, preEnd, mpp);
}

//2nd
//TC - O(NlogN + N)
//SC - O(N)

TreeNode<int> *buildBT(vector<int> &inorder, int inStart, int inEnd, vector<int> &preorder, int preStart, int preEnd, map<int, int> &mpp)
{
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    TreeNode<int> *node = new TreeNode<int>(preorder[preStart]);
    int inRoot = mpp[node->data];
    int numLeft = inRoot - inStart;

    node->left = buildBT(inorder, inStart, inRoot - 1, preorder, preStart + 1, preEnd + numLeft, mpp);
    node->right = buildBT(inorder, inRoot + 1, inEnd, preorder, preStart + 1 + numLeft, preEnd, mpp);
    return node;
}

TreeNode<int> *preOrderTree(vector<int> &preorder)
{
    int inStart = 0;
    vector<int> preOrder = preorder;
    sort(preorder.begin(), preorder.end());
    int inEnd = preorder.size() - 1;
    int preStart = 0;
    int preEnd = preOrder.size() - 1;

    map<int, int> mpp;
    for (int i = 0; i <= inEnd; i++)
    {
        mpp[preorder[i]] = i;
    }

    return buildBT(preorder, inStart, inEnd, preOrder, preStart, preEnd, mpp);
}

//3RD
//TC - O(N)
//SC - O(N)

TreeNode<int> *buildBST(vector<int> &preorder, int &i, int bound)
{
    if (i == preorder.size() || preorder[i] > bound)
        return NULL;

    TreeNode<int> *node = new TreeNode<int>(preorder[i++]);

    node->left = buildBST(preorder, i, node->data);
    node->right = buildBST(preorder, i, bound);
    return node;
}

TreeNode<int> *preOrderTree(vector<int> &preorder)
{
    int i = 0;
    return buildBST(preorder, i, INT_MAX);
}