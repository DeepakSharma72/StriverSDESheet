/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
   if(root==NULL)
        return;
    int tot=0;
    if(root->left)
        tot += root->left->data;
    if(root->right)
        tot += root->right->data;
    
    
    
    if(tot < root->data){
        if(root->left)
            root->left->data=root->data;
        
        if(root->right)
            root->right->data=root->data;
    }
    
    changeTree(root->left);
    changeTree(root->right);
    
    int update=0;
    if(root->left)
        update+=root->left->data;
    if(root->right)
        update+=root->right->data;
    
    if(root->left or root->right)
         root->data=update;
}  