/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int> *flattenTree(TreeNode<int> *root)
{
    if(root == NULL)
        return root;
    TreeNode<int>* L = flattenTree(root->left);
    TreeNode<int>* R = flattenTree(root->right);
    root->left = NULL;
    if(L == NULL)
    {
        root->right = R;
        return root;
    }
    else if(R == NULL)
    {
        root->right = L;
        return root;
    }
    else
    {
      root->right = L;
      while(L->right)
      {
        L = L->right;
      }
    L->right = R;
    return root;
    }
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    return flattenTree(root);
}