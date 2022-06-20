/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void inorderTraversal(BinaryTreeNode<int> *root,vector<int> &inorder)
{
    if(root == NULL)
        return;
    inorderTraversal(root->left,inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right,inorder);
}

void preorderTraversal(BinaryTreeNode<int> *root,vector<int> &preorder)
{
    if(root == NULL)
        return;
    preorder.push_back(root->data);
    preorderTraversal(root->left,preorder);
    preorderTraversal(root->right,preorder);
}

void postorderTraversal(BinaryTreeNode<int> *root,vector<int> &postorder)
{
    if(root == NULL)
        return;
    postorderTraversal(root->left,postorder);
    postorderTraversal(root->right,postorder);
    postorder.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<int> inorder,preorder,postorder;
    inorderTraversal(root,inorder);
    preorderTraversal(root,preorder);
    postorderTraversal(root,postorder);
    vector<vector<int>> ans = {inorder,preorder,postorder};
    return ans;
}