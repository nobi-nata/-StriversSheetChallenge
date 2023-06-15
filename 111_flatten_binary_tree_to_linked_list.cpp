
// ************************************************************ 
//RECURSIVE
    void flatten(TreeNode<int> *root, TreeNode<int> *&prev)
{
    if (root == NULL)
        return;
    flatten(root->right, prev);
    flatten(root->left, prev);

    root->right = prev;
    root->left = NULL;
    prev = root;
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *prev = NULL;
    flatten(root, prev);
    return root;
}

// ************************************************************
// ITERATIVE

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    stack<TreeNode<int> *> st;
    if (root == NULL)
        return NULL;
    st.push(root);
    while (!st.empty())
    {
        TreeNode<int> *node = st.top();
        st.pop();
        if (node->right != NULL)
            st.push(node->right);
        if (node->left != NULL)
            st.push(node->left);
        if (!st.empty())
            node->right = st.top();
        node->left = NULL;
    }
    return root;
}

// ************************************************************
// MORRIS TYPE

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    if (root == NULL)
        return NULL;
    TreeNode<int> *node = root;
    while (node != NULL)
    {

        if (node->left != NULL)
        {
            TreeNode<int> *prev = node->left;
            while (prev->right != NULL)
            {
                prev = prev->right;
            }
            prev->right = node->right;
            node->right = node->left;
            node->left = NULL;
        }
        node = node->right;
    }

    return root;
}