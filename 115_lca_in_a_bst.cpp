//recursive
TreeNode<int> *LCAinaBST(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q)
{
    if (root == NULL)
        return NULL;
    if (root->data < p->data && root->data < q->data)
        return LCAinaBST(root->right, p, q);
    if (root->data > p->data && root->data > q->data)
        return LCAinaBST(root->left, p, q);
    return root;
}

//iterative

TreeNode<int> *LCAinaBST(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q)
{
    if (root == NULL)
        return NULL;
    while (root != NULL)
    {
        if (root->data < p->data && root->data < q->data)
            root = root->right;
        else if (root->data > p->data && root->data > q->data)
            root = root->left;
        else
            return root;
    }
}
