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

int KthLargestNumber(TreeNode<int>* root, int k) 
{
     int ans = -1;
     int ctr = 0;
     while(root)
     {
         if(root->right)
         {
             TreeNode<int>* suc = root->right;
             while(suc->left != NULL && suc->left != root)
             {
                 suc = suc->left;
             }
             if(suc->left == NULL)
             {
                 suc->left = root;
                 root = root->right;
             }
             else
             {
                 ctr++;
                 if(ctr == k)
                 {
                     ans = root->data;
                 }
                 suc->left = NULL;
                 root = root->left;
             }
         }
         else
         {
             ctr++;
             if(ctr == k)
             {
                 ans = root->data;
             }
             root = root->left;
         }
     }
    return ans;
}
