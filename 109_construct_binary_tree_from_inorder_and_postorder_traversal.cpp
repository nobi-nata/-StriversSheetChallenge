/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *buildBT(vector<int> &inOrder, int iS, int iE, vector<int> &postOrder, int pS, int pE, map<int, int> &mpp)
    {
        if (pS > pE || iS > iE)
            return NULL;

        TreeNode *node = new TreeNode(postOrder[pE]);

        int inIndex = mpp[postOrder[pE]];
        int num = inIndex - iS;

        node->left = buildBT(inOrder, iS, inIndex - 1, postOrder, pS, pS + num - 1, mpp);
        node->right = buildBT(inOrder, inIndex + 1, iE, postOrder, pS + num, pE - 1, mpp);
        return node;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int iS = 0;
        int iE = inorder.size() - 1;
        int pS = 0;
        int pE = postorder.size() - 1;
        map<int, int> mpp;
        for (int i = 0; i <= iE; i++)
        {
            mpp[inorder[i]] = i;
        }
        return buildBT(inorder, iS, iE, postorder, pS, pE, mpp);
    }
};