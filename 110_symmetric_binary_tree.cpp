/*****************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

******************************************************/
bool isMirror(BinaryTreeNode<int> *Left, BinaryTreeNode<int> *Right)
{
    if (Left == NULL || Right == NULL)
        return (Left == Right);

    if (Left->data != Right->data)
        return false;

    return (isMirror(Left->left, Right->right) && isMirror(Left->right, Right->left));
}

bool isSymmetric(BinaryTreeNode<int> *root)
{
    return ((root == NULL) || isMirror(root->left, root->right));
}