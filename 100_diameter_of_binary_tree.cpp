//BRUTE FORCE
//TC - O(N^2)

int height(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + (max(height(root->left), height(root->right)));
}
void diameter(TreeNode<int> *root, int &ans)
{
    if (root == NULL)
        return;
    int lh = height(root->left);
    int rh = height(root->right);
    diameter(root->left, ans);
    diameter(root->right, ans);
    ans = max(ans, lh + rh);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    diameter(root, ans);
    return ans;
}

//OPTIMAL
//TC - O(N)

int height(TreeNode<int> *root, int &ans)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left, ans);
    int rh = height(root->right, ans);
    ans = max(ans, lh + rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    int ans = 0;
    height(root, ans);
    return ans;
}
