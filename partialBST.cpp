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
bool isvalid(BinaryTreeNode<int> *root,int lo,int up)
{
    if(root == NULL)
        return true;
    if(root->data < lo || root->data > up)
        return false;
    return (isvalid(root->left,lo,root->data) & isvalid(root->right,root->data,up));
}
bool validateBST(BinaryTreeNode<int> *root) {
    return isvalid(root,-1e9-1,1e9+1);
}