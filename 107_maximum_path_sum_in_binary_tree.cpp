#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>* root){
    return (root->left == NULL && root->right == NULL);
}

long long maxPath(TreeNode<int>* root, long long &maxi, int &cnt){
    if(root!=NULL && isLeaf(root)) cnt++;
    if(root == NULL) return 0;
    long long zero = 0;
    long long ls = max(zero, maxPath(root->left, maxi, cnt));
    long long rs = max(zero, maxPath(root->right, maxi, cnt));


    maxi = max(maxi, root->val+ls+rs);
    return root->val + max(ls,rs);
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    long long maxi = 0;
    int cnt = 0;
    maxPath(root, maxi, cnt);
    if(cnt <= 1) return -1;
    return maxi;
}