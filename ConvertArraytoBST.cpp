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
TreeNode<int>* BuildBST(vector<int> &arr,int lo,int hg)
{
    if(lo > hg)
        return NULL;
    int mid = (lo+hg)/2;
    TreeNode<int>* node = new TreeNode<int>(arr[mid]);
    node->left = BuildBST(arr,lo,mid-1);
    node->right = BuildBST(arr,mid+1,hg);
    return node;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    TreeNode<int>* ans = BuildBST(arr,0,n-1);
    return ans;
}