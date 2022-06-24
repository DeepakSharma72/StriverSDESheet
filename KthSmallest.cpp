/************************************************************

    Following is the TreeNode class structure

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

int kthSmallest(TreeNode<int> *root, int k)
{
    int ans = -1;
    int ctr = 0;
    while(root)
    {
        if(root->left)
        {
            TreeNode<int> *pred = root->left;
            while(pred->right != NULL && pred->right != root)
            {
                pred = pred->right;
            }
            if(pred->right == NULL)
            {
                pred->right = root;
                root = root->left;
            }
            else
            {
                ctr++;
                if(ctr == k)
                {
                    ans = root->data;
                }
                pred->right = NULL;
                root = root->right;
            }
        }
        else
        {
            ctr++;
            if(ctr == k)
            {
                ans = root->data;
            }
            root = root->right;
        }
    }
    return ans;
}