/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
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

TreeNode<int> *buildBT(vector<int> &inorder,vector<int> &postorder,int lo,int hg,int &idx)
{
    if(lo > hg)
        return NULL;
    
    int tar = postorder[idx--];
    int po = search(inorder,tar,lo,hg);
    TreeNode<int>* root = new TreeNode<int>(tar);
    root->right = buildBT(inorder,postorder,po+1,hg,idx);
    root->left = buildBT(inorder,postorder,lo,po-1,idx);
    return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	int idx = inOrder.size()-1;
    return buildBT(inOrder,postOrder,0,inOrder.size()-1,idx);
}
