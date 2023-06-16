#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

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
class NodeValue
{
public:
    int maxValue, minValue, maxSize;
    NodeValue(int min, int max, int size)
    {
        maxValue = max;
        minValue = min;
        maxSize = size;
    }
};

NodeValue largestBSTHelper(TreeNode<int> *root)
{
    if (root == NULL)
        return NodeValue(INT_MAX, INT_MIN, 0);

    auto left = largestBSTHelper(root->left);
    auto right = largestBSTHelper(root->right);

    if (left.maxValue < root->data && root->data < right.minValue)
    {
        return NodeValue(min(root->data, left.minValue), max(root->data, right.maxValue), 1 + left.maxSize + right.maxSize);
    }
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}
int largestBST(TreeNode<int> *root)
{
    return largestBSTHelper(root).maxSize;
}
