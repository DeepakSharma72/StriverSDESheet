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
struct TreeNode{
    bool isbalanced;
    int height;
    TreeNode(bool isb,int hg)
    {
        isbalanced = isb;
        height = hg;
    }
};

TreeNode isBalanced(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return TreeNode(true,0);
    }
    TreeNode L = isBalanced(root->left);
    TreeNode R = isBalanced(root->right);
    if(L.isbalanced == false || R.isbalanced == false || abs(L.height - R.height) > 1)
    {
        return TreeNode(false,-1);
    }
    
    return TreeNode(true,max(L.height,R.height)+1);
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    TreeNode ans = isBalanced(root);
    return ans.isbalanced;
}