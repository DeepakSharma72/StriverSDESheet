/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void getAns(TreeNode<int> *root,int tar,int &ans)
{
    if(root == NULL)
        return;
    if(root->val == tar)
    {
        ans = tar;
        return;
    }
    if(root->val > tar)
    {
        getAns(root->left,tar,ans);
    }
    else
    {
       ans = root->val;
       getAns(root->right,tar,ans);   
    }
}

int floorInBST(TreeNode<int> * root, int X)
{
    int ans = 0;
    getAns(root,X,ans);
    return ans;
}