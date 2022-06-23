/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    if(root == NULL)
        return root;
    if(P->data < Q->data)
    {
        if(root->data >= P->data && root->data <= Q->data)
            return root;
    }
    else
    {
        if(root->data >= Q->data && root->data <= P->data)
            return root;
    }
    TreeNode<int>* L = NULL,*R = NULL;
    if(P->data < root->data && Q->data < root->data)
        L = LCAinaBST(root->left,P,Q);
    if(P->data > root->data && Q->data > root->data)
        R = LCAinaBST(root->right,P,Q);
    if(L != NULL && R != NULL)
        return root;
    if(L != NULL)
        return L;
    if(R != NULL)
    return R;
    return NULL;
}
