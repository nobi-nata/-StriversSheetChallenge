#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/


//Recursive solution
//TC - O(N)
//SC - O(N)
void inO(TreeNode* node, vector<int> &inorder){
    if(node == NULL){
        return;
    }
    inO(node->left, inorder);
    inorder.push_back(node->data);
    inO(node->right, inorder);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> inorder;
    inO(root, inorder);
    return inorder;
}


//ITERATIVE SOLUTION
//TC - O(N)
//SC - O(N)

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> inorder;
    stack<TreeNode *> st;
    TreeNode *node = root;
    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
                break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
}