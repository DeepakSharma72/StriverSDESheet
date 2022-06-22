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

int search(vector<int> &inorder,int tar,int lo, int hg)
{
    while(lo <= hg)
    {
        if(inorder[lo] == tar)
            return lo;
        lo++;
    }
    return -1;
}

TreeNode<int> *buildBT(vector<int> &inorder,vector<int> &preorder,int lo,int hg,int &idx)
{
    if(lo > hg)
        return NULL;
    
    int tar = preorder[idx++];
    int po = search(inorder,tar,lo,hg);
    TreeNode<int>* root = new TreeNode<int>(tar);
    root->left = buildBT(inorder,preorder,lo,po-1,idx);
    root->right = buildBT(inorder,preorder,po+1,hg,idx);
    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int idx = 0;
	return buildBT(inorder,preorder,0,inorder.size()-1,idx);
}