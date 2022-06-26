/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
BinaryTreeNode<int>* B2DL(BinaryTreeNode<int>* root)
{
    if(root == NULL)
        return NULL;
    BinaryTreeNode<int>* lh = B2DL(root->left);
    BinaryTreeNode<int>* rh = B2DL(root->right);
    root->right = rh;
    BinaryTreeNode<int>* ptr = lh;
    if(lh == NULL)
    {
        return root;
    }
    while(ptr->right)
    {
        ptr = ptr->right;
    }
    ptr->right = root;
    return lh;
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    return B2DL(root);
}