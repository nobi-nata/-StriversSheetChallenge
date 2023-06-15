
//************************************************************* /
// 1ST
//TC - O(N^2)
    TreeNode<int> *preOrderTree(vector<int> &preOrder)
{
    int n = preOrder.size();
    TreeNode<int> *root = new TreeNode<int>(preOrder[0]);
    for (int i = 1; i < n; i++)
    {
        TreeNode<int> *node = root;
        while (node->left || node->right)
        {
            if (node->data > preOrder[i])
                if (node->left)
                    node = node->left;
                else
                    break;
            else if (node->right)
                node = node->right;
            else
                break;
        }
        if (node->data > preOrder[i])
            node->left = new TreeNode<int>(preOrder[i]);
        else
            node->right = new TreeNode<int>(preOrder[i]);
    }
    return root;
}

