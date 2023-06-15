
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty())
    {
        int n = q.size();
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            int index = leftToRight ? i : n - 1 - i;
            temp[index] = node->data;
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        leftToRight = !leftToRight;
        for (auto i : temp)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
