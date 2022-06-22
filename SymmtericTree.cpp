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
bool issymmetry(BinaryTreeNode<int> *L,BinaryTreeNode<int> *R)
{
    if(L == NULL && R == NULL)
        return true;
    if(L == NULL || R == NULL)
        return false;
    if(L->data != R->data)
        return false;
    return (issymmetry(L->left,R->right) & issymmetry(L->right,R->left));
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root == NULL)
        return true;
    return issymmetry(root->left,root->right);
}