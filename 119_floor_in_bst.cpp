
int floorInBST(TreeNode<int> *root, int X)
{
    int ans = 0;
    while (root != NULL)
    {
        if (root->val > X)
        {
            root = root->left;
        }
        else
        {
            ans = root->val;
            root = root->right;
        }
    }
    return ans;
}