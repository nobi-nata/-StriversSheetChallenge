//BRUTE FORCE
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + (max(height(root->left), height(root->right)));
}
bool isBTB(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) > 1)
        return false;

    if (!isBTB(root->left) || !isBTB(root->right))
        return false;

    return true;
}

bool isBalancedBT(BinaryTreeNode<int> *root)
{
    return isBTB(root);
}

//OPTIMAL
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);

    if (lh == -1 || rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;

    return 1 + max(lh, rh);
}

bool isBalancedBT(BinaryTreeNode<int> *root)
{
    return (height(root) != -1);
}